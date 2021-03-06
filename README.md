# gtrim
Trim implementation in C

## API

### `char *trim(char *str)`
Remove leading and trailing whitespace ( \t\n\r\x0B\x0C) from `str`.

### `char *ltrim(char *str)`
Remove leading whitespace ( \t\n\r\x0B\x0C) from `str`.

### `char *rtrim(char *str)`
Remove trailing whitespace ( \t\n\r\x0B\x0C) from `str`.

### `char *trim_chars(char *str, const char *rem)`
Remove leading and trailing chars pointed by `rem` from `str`.

### `char *ltrim_chars(char *str, const char *rem)`
Remove leading chars pointed by `rem` from `str`.

### `char *rtrim_chars(char *str, const char *rem)`
Remove trailing chars pointed by `rem` from `str`.

## Licence
The MIT License (MIT)
Copyright (c) 2015 Gianis Vrentzos <gvre@gvre.gr>

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
'Software'), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
