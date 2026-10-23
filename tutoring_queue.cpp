/*
 * Course: COEN 2220 - Programming 2
 * Name: Mario A. Marrero Colón
 * Lab: Lab 10 - Stacks & Queues
 * Description: Practice - a dynamic queue of tutoring requests
 * Due date: 23/Oct/2026
 */

#include <iostream>
#include <string>
using namespace std;

class TutoringQueue
{
private:
    struct Node
    {
        string studentId; // Store one student waiting for tutoring.
        Node *next;       // Point to the student immediately behind this one.
    };

    Node *front; // Point to the student who must be served next.
    Node *rear;  // Point to the student most recently added.

public:
    TutoringQueue()
    {
        front = nullptr;
        rear = nullptr;
    }

    ~TutoringQueue()
    {
        while (front != nullptr)
        {
            Node *nodeToDelete = front;
            front = front->next; // Advance before releasing the current node.
            delete nodeToDelete;
        }

        rear = nullptr;
    }

    bool isEmpty() const
    {
        return front == nullptr;
    }

    // ===== Resolve these TODOs now (Part E) =====
    // TODO (Part E): Write enqueue to add newStudentId at rear.
    void enqueue(const string& newStudentId)
    {
        Node *newNode = new Node;
        newNode->studentId = newStudentId;
        newNode->next = nullptr;

        if (isEmpty())
        {
            front = newNode;
        }
        else
        {
            rear->next = newNode;
        }
        rear = newNode;
    }
    // TODO (Part E): Write dequeue. It returns bool and uses string& servedStudentId.
    bool dequeue(string& servedStudentId)
    {
        if (isEmpty())
        {
            return false;
        }
        Node *nodeToDelete = front;
        servedStudentId = front->studentId;
        front = front->next;
        delete nodeToDelete;
        return true;
    }
};

int main()
{
    cout << boolalpha;

    // TODO (Part E): Create a TutoringQueue object.
    TutoringQueue tutoringQueue;
    // TODO (Part E): Add TU-301, TU-318, and TU-327 in that arrival order.
    tutoringQueue.enqueue("TU-301");
    tutoringQueue.enqueue("TU-318");
    tutoringQueue.enqueue("TU-327");
    // TODO (Part E): Dequeue and print the first two served student IDs.
    string servedStudentId;
    tutoringQueue.dequeue(servedStudentId);
    cout << "Served student: " << servedStudentId << endl;
    tutoringQueue.dequeue(servedStudentId);
    cout << "Served student: " << servedStudentId << endl;
    // TODO (Part E): Dequeue the last student, then print whether the queue is empty.
    tutoringQueue.dequeue(servedStudentId);
    cout << "Served student: " << servedStudentId << endl;
    cout << "Queue empty: " << tutoringQueue.isEmpty() << endl;
    // TODO (Part E): Add TU-340 after the queue becomes empty, dequeue it, and print its ID.
    tutoringQueue.enqueue("TU-340");
    tutoringQueue.dequeue(servedStudentId);
    cout << "Served student after empty queue: " << servedStudentId << endl;

    return 0;
}

/*
 * Analysis Answers
 *
 * E1 — First arrival
 * Why must the first call to enqueue assign newNode to both front and rear?
 * Answer:
 * Because Its both the first and the last node, so both pointers must point to it.
 *
 * E2 — Last departure
 * After dequeue removes the only remaining node, what must happen to rear and why?
 * Answer:
 * rear must become nullptr so the queue knows it is empty.
 *
 * E3 — FIFO evidence
 * List the expected service order for TU-301, TU-318, and TU-327. Explain why this
 * differs from the return order of the function-call stack in Part D.
 * Answer:
 * TU-301, TU-318, TU-327. Queues use FIFO, while stacks use LIFO.
 *
 */