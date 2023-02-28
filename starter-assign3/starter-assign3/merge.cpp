/*
 * TODO: remove and replace this file header comment
 * You will edit and turn in this file.
 * Remove starter comments and add your own
 * comments on each function and on complex code sections.
 */
#include <iostream>    // for cout, endl
#include "queue.h"
#include "testing/SimpleTest.h"
using namespace std;

/*
 * This function returns two sorted Queues merged together.
 * Input: Sorted Queues
 * Output: One sorted, merged queue
 * I was able to implement this function.
 */
Queue<int> binaryMerge(Queue<int> a, Queue<int> b) {
    Queue<int> result;
    int holdA;
    int holdB;

    while(!a.isEmpty()&&!b.isEmpty()){
        if(a.peek()>b.peek()){
            holdB=b.dequeue();
            if(!b.isEmpty()&&holdB>b.peek()){
                error("b is not in order");
            }
            result.enqueue(holdB);
            if(a.isEmpty()||b.isEmpty()){
                break;
            }
        }
        if(a.peek()<=b.peek()){
            holdA=a.dequeue();
            if(!a.isEmpty()&&holdA>a.peek()){
                error("a is not in order");
            }
            result.enqueue(holdA);
            if(a.isEmpty()||b.isEmpty()){
                break;
            }
        }
    }
    while(!a.isEmpty()&&b.isEmpty()){
        holdA=a.dequeue();
        if(!a.isEmpty()&&holdA>a.peek()){
            error("a is not in order");
        }
        result.enqueue(holdA);
    }
    while(a.isEmpty()&&!b.isEmpty()){
        holdB=b.dequeue();
        if(!b.isEmpty()&&holdB>b.peek()){
            error("b is not in order");
        }
        result.enqueue(holdB);
    }

    return result;
}

/*
 * This function assumes correct functionality of the previously
 * defined binaryMerge function and makes use of this function to
 * iteratively merge a collection of sequences, starting off with
 * an empty sequence and progressively merging in one sequence at
 * a time. This function is provided for you fully implemented –
 * it does not need to modified at all.
 */
Queue<int> naiveMultiMerge(Vector<Queue<int>>& all) {
    Queue<int> result;

    for (Queue<int>& q : all) {
        result = binaryMerge(q, result);
    }
    return result;
}

/*
 * This function takes as input a vector queue. It will return, sorted, all the queues inside of the function.
 Input: Vector Queue
 Output: Sorted Queues
 I was not able to implement this function and needed help for it.
 */
Queue<int> recMultiMerge(Vector<Queue<int>>& all) {
    Queue<int> result;
    if(all.isEmpty()){
        return result;
    }
    else if(all.size()==1){
        return all[0];
    }
    else{
        Vector<Queue<int>>left=all.subList(0,all.size()/2);
        Vector<Queue<int>>right=all.subList(all.size()/2,all.size()-all.size()/2);
        Queue<int>leftCombine=recMultiMerge(left);
        Queue<int>rightCombine=recMultiMerge(right);
        return result = binaryMerge(leftCombine,rightCombine);
    }
}
    /*My buggy code
     *
     * Vector<Queue<int>>sublistb=all.subList(all.size()/2,all.size()-all.size()/2);
    Vector<Queue<int>>sublistA=all.subList(0,all.size()/2);
    all.clear();

    if(sublistA.size()==0){
        return {};
    }
    if(sublistA.size()!=0){
       return recMultiMerge(sublistA);
    }
return result;*/
/* * * * * * Test Cases * * * * * */

Queue<int> createSequence(int size);
void distribute(Queue<int> input, Vector<Queue<int>>& all);

PROVIDED_TEST("binaryMerge, two short sequences") {
    Queue<int> a = {2, 4, 5};
    Queue<int> b = {1, 3, 3};
    Queue<int> expected = {1, 2, 3, 3, 4, 5};
    EXPECT_EQUAL(binaryMerge(a, b), expected);
    EXPECT_EQUAL(binaryMerge(b, a), expected);
}

PROVIDED_TEST("naiveMultiMerge, small collection of short sequences") {
    Vector<Queue<int>> all = {{3, 6, 9, 9, 100},
                             {1, 5, 9, 9, 12},
                             {5},
                             {},
                             {-5, -5},
                             {3402}
                            };
    Queue<int> expected = {-5, -5, 1, 3, 5, 5, 6, 9, 9, 9, 9, 12, 100, 3402};
    EXPECT_EQUAL(naiveMultiMerge(all), expected);
}

PROVIDED_TEST("recMultiMerge, compare to naiveMultiMerge") {
    int n = 20;
    Queue<int> input = createSequence(n);
    Vector<Queue<int>> all(n);
    distribute(input, all);
    EXPECT_EQUAL(recMultiMerge(all), naiveMultiMerge(all));
}

PROVIDED_TEST("Time binaryMerge operation") {
    int n = 1000000;
    Queue<int> a = createSequence(n);
    Queue<int> b = createSequence(n);
    TIME_OPERATION(a.size() + b.size(), binaryMerge(a, b));
}

PROVIDED_TEST("Time naiveMultiMerge operation") {
    int n = 11000;
    int k = n/10;
    Queue<int> input = createSequence(n);
    Vector<Queue<int>> all(k);
    distribute(input, all);
    TIME_OPERATION(input.size(), naiveMultiMerge(all));
}
PROVIDED_TEST("Time recMultiMerge operation") {
    int n = 90000;
    int k = n/10;
    Queue<int> input = createSequence(n);
    Vector<Queue<int>> all(k);
    distribute(input, all);
    TIME_OPERATION(input.size(), recMultiMerge(all));
}
//Student Tests


STUDENT_TEST("binaryMerge, b empty") {
    Queue<int> a = {2, 4, 5};
    Queue<int> b = {};
    Queue<int> expected = {2,4,5};
    EXPECT_EQUAL(binaryMerge(a, b), expected);
    EXPECT_EQUAL(binaryMerge(b, a), expected);
}
STUDENT_TEST("binaryMerge, a empty") {
    Queue<int> a = {};
    Queue<int> b = {2, 4, 5};
    Queue<int> expected = {2,4,5};
    EXPECT_EQUAL(binaryMerge(a, b), expected);
    EXPECT_EQUAL(binaryMerge(b, a), expected);
}
STUDENT_TEST("binaryMerge, a out of order") {
    Queue<int> a = {1,3,2};
    Queue<int> b = {2, 4, 5};
    Queue<int> expected = {2,4,5};
    EXPECT_ERROR(binaryMerge(a, b));
    EXPECT_ERROR(binaryMerge(b, a));
}

// Test helper to fill queue with sorted sequence
Queue<int> createSequence(int size) {
    Queue<int> q;
    for (int i = 0; i < size; i++) {
        q.enqueue(i);
    }
    return q;
}

//Test helper to distribute elements of sorted sequence across k sequences,
 //  k is size of Vector
void distribute(Queue<int> input, Vector<Queue<int>>& all) {
    while (!input.isEmpty()) {
        all[randomInteger(0, all.size()-1)].enqueue(input.dequeue());
    }
}

STUDENT_TEST("recMultiMerge, small collection of short sequences") {
    Vector<Queue<int>> all = {
                             {-5},
                             {5,5},
                             {5,8}
                            };
    Queue<int> expected = {-5, 5,5,5,8};
    EXPECT_EQUAL(recMultiMerge(all), expected);
}
STUDENT_TEST("recMultiMerge, small collection of short sequences") {
    Vector<Queue<int>> all = {{3, 6, 9, 9, 100},
                             {1, 5, 9, 9, 12},
                             {5},
                             {-5, -5},
                            };
    Queue<int> expected = {-5, -5, 1, 3, 5, 5, 6, 9, 9, 9, 9, 12, 100};
    EXPECT_EQUAL(recMultiMerge(all), expected);
}

STUDENT_TEST("recMultiMerge, small collection of short sequences, out of order expect an error") {
    Vector<Queue<int>> all = {
                             {5},
                             {5,-5},
                            };
    Queue<int> expected = {-5, 5};
    EXPECT_EQUAL(recMultiMerge(all), expected);
}
