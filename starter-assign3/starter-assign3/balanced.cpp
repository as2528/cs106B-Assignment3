/*
 * TODO: remove and replace this file header comment
 * You will edit and turn in this file.
 * Remove starter comments and add your own
 * comments on each function and on complex code sections.
 */
#include <iostream>    // for cout, endl
#include <string>      // for string class
#include "recursion.h"
#include "testing/SimpleTest.h"

using namespace std;
//string strTemp;
/*
 * This program will take a string, and will return if the brackets and parentheses used in the string are balanced.
 */

/*  Input: String
 * Output: String with the parentheses and brackets in the order they are in the string
 *
 */
string operatorsFrom(string str) {

    if(str.length()>0){
        if((str[0] == '(')||(str[0] == ')')||(str[0] == '}')||(str[0] == '[')||(str[0] == ']')||(str[0] == '{')||(str[0] == '}')){
            return str[0] + operatorsFrom(str.substr(1));
        }
        else {
            return operatorsFrom(str.substr(1));
        }
        }
        else {
            return "";
        }
}

/*Input: String with parentheses and brackets.
 * Output: True if string is balanced, false otherwise.
 */
bool operatorsAreMatched(string ops) {

    int i = ops.find(')');//Need these or out of bounds errors will occur.
    int j = ops.find(']');
    int k = ops.find('}');

    if(ops.length()==0){
        return true;
    }
    if((ops[0]=='('&&ops.find(')')==1&&i>0)||(ops[0]=='('&&ops.find(')')%2!=0&&i>0)){
        return operatorsAreMatched(ops.substr(1).erase(ops.find(')')-1,1));
    }
    if((ops[0]=='['&&ops.find(']')==1&&j>0)||(ops[0]=='['&&ops.find(']')%2!=0&&j>0)){
        return operatorsAreMatched(ops.substr(1).erase(ops.find(']')-1,1));
    }
    if((ops[0]=='{'&&ops.find('}')==1&&k>0)||(ops[0]=='{'&&ops.find('}')%2!=0&&k>0)){
        return operatorsAreMatched(ops.substr(1).erase(ops.find('}')-1,1));
    }
    if((ops[0]=='('&&(ops[ops.length()-1]==')'))||(ops[0]=='{'&&(ops[ops.length()-1]=='}'))||(ops[0]=='['&&(ops[ops.length()-1]==']')))
        return operatorsAreMatched(ops.substr(1,ops.length()-2));
    else{
        return false;
    }

}

/*
 * The isBalanced function assumes correct implementation of
 * the above two functions operatorsFrom and operatorsMatch.
 * It uses operatorsFrom to extract the operator characters
 * from the input string and then confirms that those
 * operators are balanced by using operatorsMatch.
 * You should not modify the provided code in the isBalanced
 * function.  If the previous two functions have been implemented
 * correctly, the provided isBalanced will correctly report whether
 * the input string has balanced bracketing operators.
 */
bool isBalanced(string str) {
    string ops = operatorsFrom(str);
    return operatorsAreMatched(ops);
}


/* * * * * * Test Cases * * * * * */

PROVIDED_TEST("operatorsFrom on simple example") {
    EXPECT_EQUAL(operatorsFrom("vec[3]"), "[]");
}

PROVIDED_TEST("operatorsAreMatched on simple example") {
    EXPECT(operatorsAreMatched("{}"));
}

PROVIDED_TEST("isBalanced on example from writeup") {
    string example ="int main() { int x = 2 * (vec[2] + 3); x = (1 + random()); }";
    EXPECT(isBalanced(example));
}

PROVIDED_TEST("isBalanced on non-balanced examples from writeup") {
    EXPECT(!isBalanced("( ( [ a ] )"));
    EXPECT(!isBalanced("3 ) ("));
    EXPECT(!isBalanced("{ ( x } y )"));
}
//Student tests

STUDENT_TEST("operatorsFrom on simple example") {
    EXPECT_EQUAL(operatorsFrom("e(ct)"), "()");
    EXPECT_EQUAL(operatorsFrom("e(ct)]"), "()]");
}
