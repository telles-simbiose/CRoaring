#include <assert.h>
#include <roaring/roaring.h>

typedef struct roaring_bitmap_writer_s {
    uint64_t *bitmap;
    roaring_bitmap_t *target;
    uint32_t current_key;
    uint64_t cardinality;
    bool dirty;
} roaring_bitmap_writer_t;

roaring_bitmap_writer_t *roaring_bitmap_writer_create(roaring_bitmap_t *target);

void roaring_bitmap_writer_free(roaring_bitmap_writer_t *writer);

void roaring_bitmap_writer_flush(roaring_bitmap_writer_t *writer);

void roaring_bitmap_writer_add(roaring_bitmap_writer_t *writer, const uint32_t val);
