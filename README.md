# libdop

`libdop` is a C utilities library by Simon Doppler.

It features hash capabilities, double computations as well as memory
and string operations.

## Double operations

* @ref max
* @ref min
* @ref range
* @ref sum
* @ref mean
* @ref median
* @ref variance
* @ref standart_deviation

## Filesystem operations

* @ref remove_r

## Memory operations

* @ref buffer_length_check

## Hashing

* @ref hexdump
* @ref hash_djb2

## String operations

* @ref strcharcount
* @ref trimwhitespace

## About

### Versionning

This project follows the semantic versionning guidelines provided at
[semver.org](http://semver.org/) with versions numbered as `MAJOR.MINOR.
REVISION` :

* `MAJOR` is increased after a backwards incompatible API change.
* `MINOR` is increased after a backwards compatible API change.
* `REVISION` is increased after a change with no effect on the API.

Any version with `MAJOR` being 0 *should* not be considered stable nor
should its API.

Versions history can be found in the file ChangeLog.md

### Author

`libdop` (c) 2016 Simon Doppler *<dopsi.dev@gmail.com>*
