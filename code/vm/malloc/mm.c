/* Basic constants and macros */
#define WSIZE  4 /* Word and header/footer size (bytes) */
#define DSIZE  8 /* Double word size (bytes) */
#define CHUNKSIZE (1<<12) /* Extend heap by this amount (bytes) */

#define MAX(x, y) ((x) > (y) ? (x) : (y))

/* Pack a size and allocated bit into a word */
#define PACK(size, alloc) ((size) | (alloc))

/* Read and write a word at address p */
#define GET(p) (*(unsigned int *)(p))
#define PUT(p, val) (*(unsigned int *)(p) = (val))

/* Read the size and allocated fields from address p */
#define GET_SIZE(p) (GET(p) & ~0x7)
#define GET_ALLOC(p) (GET(p) & 0x1)

/* Given block ptr bp, compute address of its header and footer */
#define HDRP(bp)   ((char *)(bp) - WSIZE)
#define FTRP(bp)   ((char *)(bp) + GET_SIZE(HDRP(bp)) -DSIZE)

/* Given block ptr bp, compute address of next and previous blocks */
#define NEXT_BLKP(bp) ((char *)(bp) + GET_SIZE(((char *)(bp) - WSIZE)))
#define PREV_BLKP(bp) ((char *)(bp) - GET_SIZE(((char *)(bp) - DSIZE)))

int mm_init(void)
{
  /* Create the initial empty heap */
  if ((heap_listp = mem_sbrk(4*WSIZE)) == (void *)-1)
    return -1;
  PUT(heap_listp, 0);
  PUT(heap_listp + (1*WSIZE), PACK(DSIZE, 1));
  PUT(heap_listp + (2*WSIZE), PACK(DSIZE, 1));
  PUT(heap_listp + (3*WSIZE), PACK(0, 1));
  heap_listp += (2*WSIZE);

  /* Extend the empty heap with a free block of CHUNKSIZE bytes */
  if (extend_heap(CHUNKSIZE/WSIZE) == NULL)
    return -1;
  return 0;
}

static void *extend_heap(size_t words)
{
  char *bp;
  size_t size;

  /* Allocate an even number of words to maintain alignment */
  size=(words % 2) ? (words+1) * WSIZE : words * WSIZE;
  if ((long)(bp = mem_sbrk(size)) == -1)
    return NULL;

  /* Initialize free block header/footer and the epilogue header */
  PUT(HDPR(bp), PACK(size, 0));    /* Free block header */
  PUT(FTPR(bp), PACK(size, 0));    /* Free block footer */
  PUT(HDPR(NEXT_BLKP(bp)), PACK(0, 1)); /* New epilogue header */

  /* Coalesce if the previous block was free */
  return coalesce(bp);
}
