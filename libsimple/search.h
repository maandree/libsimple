/* See LICENSE file for copyright and license details. */


/**
 * Find, using binary search, the position where an item in
 * sorted list is located or should be located
 * 
 * @param   key     The item to find the position for
 * @param   base    Sorted array to search
 * @param   nel     The number of elements in `base`
 * @param   width   The byte-width of each element in `base`
 * @param   compar  Function used to compare `key` against an element
 *                  in the array. The function be given two arguments:
 *                  the first argument will always be `key`, the other
 *                  will be an element in `base`. The function shall
 *                  return a negative value if first argument shall
 *                  precede the second argument when sorted into the
 *                  list, or a positive value if the first argument
 *                  shall succeed the second argument, but if the
 *                  two argument are equal, the function shall return 0.
 * @return          If the function finds `key` in `base`, it returns
 *                  the index (starting from 0) of some such element
 *                  in `base`, however if `key` is not found, the
 *                  function returns the bitwise complement the index
 *                  to each `key` may be inserted.
 * 
 * @seealso  bsearch(3p)
 * @seealso  libsimple_bindex_r(3p)
 */
ssize_t libsimple_bindex(const void *key, const void *base, size_t nel, size_t width, /* TODO man */
                         int (*compar)(const void *, const void *));
#ifndef bindex
# define bindex(...) libsimple_bindex(__VA_ARGS__)
#endif

/**
 * Find, using binary search, the position where an item in
 * sorted list is located or should be located
 * 
 * @param   key     The item to find the position for
 * @param   base    Sorted array to search
 * @param   nel     The number of elements in `base`
 * @param   width   The byte-width of each element in `base`
 * @param   compar  Function used to compare `key` against an element
 *                  in the array. The function be given three arguments:
 *                  the first argument will always be `key`, the second
 *                  will be an element in `base`, and the third will
 *                  always be `arg`. The function shall return a negative
 *                  value if first argument shall precede the second
 *                  argument when sorted into the list, or a positive
 *                  value if the first argument shall succeed the second
 *                  argument, but if the two argument are equal, the
 *                  function shall return 0.
 * @param   arg     User-defined value that is passed directly into
 *                  `compar` as the third argument at each callback
 * @return          If the function finds `key` in `base`, it returns
 *                  the index (starting from 0) of some such element
 *                  in `base`, however if `key` is not found, the
 *                  function returns the bitwise complement the index
 *                  to each `key` may be inserted.
 * 
 * @seealso  bsearch(3p)
 * @seealso  libsimple_bindex(3p)
 */
ssize_t libsimple_bindex_r(const void *key, const void *base, size_t nel, size_t width, /* TODO man */
                           int (*compar)(const void *, const void *, void *), void *arg);
#ifndef bindex_r
# define bindex_r(...) libsimple_bindex_r(__VA_ARGS__)
#endif
