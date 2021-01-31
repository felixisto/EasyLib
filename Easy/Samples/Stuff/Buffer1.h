#pragma once

#include "../../Easy.h"
#include "../../Basic/Utilities.h"
#include "../../Basic/Basic.h"
#include "../../Formatters/ByteFormatter.h"
#include "../Helpers/SampleTest.h"

namespace easy {
    namespace samples {
        struct Buffer1: SampleTest {
            bool performAll() {
                basic1();
                copy1();
                sub1();
                move1();
                return true;
            }

            void basic1() {
                printLine("basic1()");

                BytesBuffer a = BytesBuffer(8);
                ByteFormatter formatter;
                formatter.separator = "-";
                formatter.separatorValuesBySize = 2;

                printLine("zero buffer (8): %s", formatter.parse(a.buffer(), a.length()).buffer());

                a.setLength(16);

                printLine("zero buffer (16): %s", formatter.parse(a.buffer(), a.length()).buffer());

                a[0] = 'a';
                a[1] = 'b';
                a[2] = 'c';
                a[3] = 'd';

                printLine("buffer (16): %s", formatter.parse(a.buffer(), a.length()).buffer());

                a.setLength(20);

                printLine("buffer (20): %s", formatter.parse(a.buffer(), a.length()).buffer());

                BytesBuffer b = a;

                printLine("buffer b (20): %s", formatter.parse(b.buffer(), b.length()).buffer());
            }

            void copy1() {
                printLine("copy1()");

                BytesBuffer a = BytesBuffer(16);
                BytesBuffer b = BytesBuffer(16);

                ByteFormatter formatter;
                formatter.separator = "-";
                formatter.separatorValuesBySize = 2;

                a[0] = 'a';
                a[1] = 'b';
                a[2] = 'c';
                a[3] = 'd';

                b[12] = '1';
                b[13] = '2';
                b[14] = '3';
                b[15] = '4';

                printLine("buffer a (16): %s", formatter.parse(a.buffer(), a.length()).buffer());
                printLine("buffer b (16): %s", formatter.parse(b.buffer(), b.length()).buffer());

                a.copyBytes(4, Range::CreateStartEnd(12, 16), b);

                printLine("copy 11,16 from buffer b into buffer a position 4");
                printLine("buffer a (16): %s", formatter.parse(a.buffer(), a.length()).buffer());
                printLine("buffer b (16): %s", formatter.parse(b.buffer(), b.length()).buffer());
            }

            void sub1() {
                printLine("sub1()");

                BytesBuffer a = BytesBuffer(16);

                ByteFormatter formatter;
                formatter.separator = "-";
                formatter.separatorValuesBySize = 2;

                a[0] = '1';
                a[1] = '2';
                a[2] = '3';
                a[3] = '4';
                a[4] = '5';
                a[5] = '6';

                printLine("buffer a (16): %s", formatter.parse(a.buffer(), a.length()).buffer());

                auto subbuffer = a.subbuffer(Range::CreateStartEnd(1, 5));

                printLine("subbuffer from buffer a [1, 5]: %s", formatter.parse(subbuffer.buffer(), subbuffer.length()).buffer());

                auto appendbuffer = subbuffer + subbuffer;

                printLine("subbuffer + subbuffer = %s", formatter.parse(appendbuffer.buffer(), appendbuffer.length()).buffer());
            }

            void move1() {
                printLine("move1()");

                BytesBuffer a = BytesBuffer(16);
                BytesBuffer b = BytesBuffer(4);

                ByteFormatter formatter;
                formatter.separator = "-";
                formatter.separatorValuesBySize = 2;

                a[0] = '1';
                a[1] = '2';
                a[2] = '3';
                a[3] = '4';
                a[4] = '5';
                a[5] = '6';

                b[0] = 'x';
                b[1] = 'z';
                b[2] = 'z';
                b[3] = 'x';

                printLine("buffer b (4): %s", formatter.parse(b.buffer(), b.length()).buffer());
                printLine("buffer a (16): %s", formatter.parse(a.buffer(), a.length()).buffer());

                a.insertBytes(6, b);

                printLine("insert b into buffer a at 6: %s", formatter.parse(a.buffer(), a.length()).buffer());

                a.insertBytes(20, b);

                printLine("insert b into buffer a at 20: %s", formatter.parse(a.buffer(), a.length()).buffer());
            }
        };
    }
};
