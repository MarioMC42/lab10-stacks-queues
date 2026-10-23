/*
 * Course: COEN 2220 - Programming 2
 * Name: Mario A. Marrero Colón
 * Lab: Lab 10 - Stacks & Queues
 * Description: Practice - a dynamic stack of active function calls
 * Due date: 23/Oct/2026
 */

#include <iostream>
#include <string>
using namespace std;

class FunctionCallStack
{
private:
    // ===== Resolve these TODOs now (Part C) =====
    // TODO (Part C): Define Node with string functionName and Node *next.
    struct Node
    {
        string functionName; // store function name
        Node *next;
    };
    // TODO (Part C): Declare Node *top for the node that must leave next.
    Node *top;

public:
    // TODO (Part C): Write a constructor that creates an empty stack.
    FunctionCallStack()
    {
        top = nullptr;
    }
    // ===== Resolve these TODOs later (Part D) =====
    // TODO (Part D): Write isEmpty as a const member function.
    bool isEmpty() const
    {
        return top == nullptr;
    }
    // TODO (Part D): Write push to add a function name at top.
    void push(const string& functionName)
    {
        Node *newNode = new Node;
        newNode->functionName = functionName;
        newNode->next = top;
        top = newNode;
    }
    // TODO (Part D): Write pop. It returns bool and uses string& removedFunctionName.
    bool pop (string& removedFunctionName)
    {
        if (isEmpty())
        {
            return false; // No function to pop from an empty stack.
        }
        Node *nodeToDelete = top;
        removedFunctionName = top->functionName;
        top = top->next; // The next function becomes the new top.
        delete nodeToDelete;
        return true;
    }
    // TODO (Part D): Write peek. It returns bool and uses string& topFunctionName.
    bool peek (string& topFunctionName) const
    {
        if (isEmpty())
        {
            return false; // No function to peek at.
        }
        topFunctionName = top->functionName;
        return true;
    }
    // TODO (Part D): Write a destructor that releases every dynamic node.
    ~FunctionCallStack()
    {
        while (top != nullptr)
        {
            Node *nodeToDelete = top;
            top = top->next;
            delete nodeToDelete;
        }
    }
};

int main()
{
    cout << boolalpha;

    // ===== Resolve these TODOs later (Part D) =====

    // TODO (Part D): Create a FunctionCallStack object.
    FunctionCallStack callStack;
    string topFunctionName;
    string removedFunctionName;
    
    // TODO (Part D): Push main, loadSchedule, and formatSchedule in that order.
    callStack.push("main");
    callStack.push("loadSchedule");
    callStack.push("formatSchedule");
    // TODO (Part D): Use peek and pop to demonstrate LIFO with descriptive output.
    callStack.peek(topFunctionName);
    cout << "Current function: " << topFunctionName << endl;

    
    callStack.pop(removedFunctionName);
    cout << "Popped function: " << removedFunctionName << endl;

    callStack.pop(removedFunctionName);
    cout << "Popped function: " << removedFunctionName << endl;

    callStack.pop(removedFunctionName);
    cout << "Popped function: " << removedFunctionName << endl;

    // TODO (Part D): Pop remaining calls, then demonstrate an unsuccessful pop on an empty stack.
    cout << "Stack empty: " << callStack.isEmpty() << endl;

    bool popSucceeded = callStack.pop(removedFunctionName);
    cout << "Attempted pop on empty stack: " << popSucceeded << endl;

    return 0;
}

/*
 * Analysis Answers
 *
 * D1 — Adding formatSchedule
 * When push("formatSchedule") executes, what must newNode->next receive before top
 * changes? Explain why reversing those two assignments would lose the previous top.
 * Answer:
 * It must receive the old top pointer. That keeps the previous stack node linked.
 * If top is changed first, the old top is lost and the stack breaks.
 *
 * D2 — Returning from a function
 * After main, loadSchedule, and formatSchedule are pushed in that order, list the
 * order in which three successful pop calls must return their names. Explain LIFO.
 * Answer:
 * formatSchedule, loadSchedule, main. LIFO means the last item pushed is the first
 * removed.
 *
 * D3 — Destructor order
 * Why must the destructor save a next-node address before deleting the current node?
 * Answer:
 * So it can still reach the next node after deleting the current one. Otherwise the
 * rest of the stack would be lost.
 *
 */