/*
 * Copyright (c) 2013, 2015, Oracle and/or its affiliates. All Rights reserved
 * 
 * The Universal Permissive License (UPL), Version 1.0
 * 
 * Subject to the condition set forth below, permission is hereby granted to any person obtaining a copy of this software,
 * associated documentation and/or data (collectively the "Software"), free of charge and under any and all copyright rights in the 
 * Software, and any and all patent rights owned or freely licensable by each licensor hereunder covering either (i) the unmodified 
 * Software as contributed to or provided by such licensor, or (ii) the Larger Works (as defined below), to deal in both
 * 
 * (a) the Software, and
 * (b) any piece of software and/or hardware listed in the lrgrwrks.txt file if one is included with the Software (each a “Larger
 * Work” to which the Software is contributed by such licensors),
 * 
 * without restriction, including without limitation the rights to copy, create derivative works of, display, perform, and 
 * distribute the Software and make, use, sell, offer for sale, import, export, have made, and have sold the Software and the 
 * Larger Work(s), and to sublicense the foregoing rights on either these or other terms.
 * 
 * This license is subject to the following condition:
 * The above copyright notice and either this complete permission notice or at a minimum a reference to the UPL must be included in 
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 * IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/************************************************************************
 *
 * @file table_test.h
 *
 * Test cases for the Table data structure.
 *
 ***********************************************************************/

#include "test.h"

#include "Table.h"

namespace test {

    template<typename C>
    int count(const C& c) {
        int res = 0;
        for(auto it = c.begin(); it != c.end(); ++it) {
            res++;
        }
        return res;
    }

    TEST(Table, Basic) {

        Table<int> table;
        EXPECT_TRUE(table.empty());
        EXPECT_EQ(0, table.size());
        EXPECT_EQ(0, count(table));

        table.insert(1);

        EXPECT_FALSE(table.empty());
        EXPECT_EQ(1, table.size());
        EXPECT_EQ(1, count(table));

    }

    TEST(Table, Stress) {

        for(int i=0; i<10000; ++i) {

            Table<int> table;

            for(int j=0; j<i; ++j) {
                table.insert(j);
            }

            EXPECT_EQ((size_t)i, table.size());

            int last = -1;
            for(const auto& cur : table) {
                EXPECT_EQ(last+1, cur);
                last = cur;
            }
            EXPECT_EQ(last+1, i);

        }

    }

}
