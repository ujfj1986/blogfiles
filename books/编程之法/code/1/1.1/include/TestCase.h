/*
 *
 * @file: TestCase.h
 * @author: Jiejing Shan
 * @comments: load test cases from the TestCase.json file.
 * @date: 19-11-27
 *
*/

#ifndef _TESTCASE_H_
#define _TESTCASE_H_

#include <string>
#include <list>
#include <map>

namespace util {

    // TestCase class
    struct AbstractTestCase {
        virtual ~AbstractTestCase() {}

        typedef struct ParamType {
            union {
                char c;
                unsigned char uc;
                int i;
                unsinged int ui;
                long l;
                unsinged long ul;
                long long ll;
                unsinged long long ull;
                float f;
                double d;
                char* pc;
                std::string str;
            } u;
            enum {
                TYPT_UNKNOW = -1,
                TYPE_CHAR = 0,
                TYPE_UCHAR = 1,
                TYPE_INT = 2,
                TYPE_UINT = 3,
                TYPE_LONG = 4,
                TYPE_ULONG = 5,
                TYPE_LONGLONG = 6,
                TYPE_ULONGLONG = 7,
                TYPE_FLOAT = 8,
                TYPE_DOUBLE = 9,
                TYPE_PCHAR = 10,
                TYPE_STRING = 11,
            } t;
        } ParamType;

        virtual ParamType getParam(std::string key);

        virtual ParamType getResult();

        private :

        std::map<std::string, ParamType> mParams;
        ParamType mResult;
    };

    class TestCaseLoader {
        public:
        template <typename T extern AbstractTestCase>
        static std::list<AbstractTestCase*> load(std::string file);
    };
}

#endif //_TESTCASE_H_