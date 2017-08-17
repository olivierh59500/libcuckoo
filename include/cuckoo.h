/*
 * This file is part of libcuckoo
 * It is free software under the LGPL 3.0
 *
 * @author Katharina "spacekookie" Fey
 */

#include <unitypes.h>

/** Forward declare our map so users can import them */
typedef struct cuckoo_map cuckoo_map;

/** Runtime flags given to initialiser **/
#define CUCKOO_DEFAULT        (1 << 1)
#define CUCKOO_QUEUED         (1 << 2)
#define CUCKOO_ASYNC          (1 << 3)
#define CUCKOO_TABLES_TWO     (1 << 4)
#define CUCKOO_TABLES_THREE   (1 << 5)
#define CUCKOO_TABLES_FOUR    (1 << 6)

/** Don't provide a callback function */
#define CUCKOO_NO_CB            NULL

#define CUCKOO_SUCCESS              (0     )
#define CUCKOO_ERROR                (1 << 0)
#define CUCKOO_MALLOC_FAIL          (1 << 1)
#define CUCKOO_INVALID_OPTIONS      (1 << 2)


/**
 * Creates a new cuckoo map with an initial size and a few runtime
 * flags that can be combined to achieve different behaviours. This
 * includes the queueing style, number of tables and hash functions.
 *
 * By default it will create two tables and use simple queuing for
 * inserting new items.
 *
 * @param map           A reference pointer to a map to be created
 * @param init_size     The initial size of the map tables
 * @param rt_flgs       Runtime flags provided via OR operator (|)
 * @return
 */
int cuckoo_init(struct cuckoo_map **map, size_t init_size, uint32_t flags);


/**
 *
 * @param map
 * @param key
 * @param data
 * @return
 */
int cuckoo_insert(struct cuckoo_map *map, const char *key, void *data);


/**
 *
 * @param map
 * @param key
 * @return
 */
int cuckoo_contains(struct cuckoo_map *map, const char *key);


/**
 *
 * @param map
 * @param key
 * @param data
 * @return
 */
int cuckoo_retrieve(struct cuckoo_map *map, const char *key, void **data);


/**
 *
 * @param map
 * @param key
 * @return
 */
int cuckoo_remove(struct cuckoo_map *map, const char *key, void (*free_cb)(void*));


/**
 *
 * @param map
 * @return
 */
int cuckoo_clear(struct cuckoo_map *map, void (*free_cb)(void*));


/**
 *
 * @param map
 * @return
 */
int cuckoo_free(struct cuckoo_map *map, void (*free_cb)(void*));
