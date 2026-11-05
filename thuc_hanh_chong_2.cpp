#include <iostream>
#include <string>

using namespace std;

#define MAX 100

struct SinhVien {
    string maSo;
    string hoTen;
};

struct Queue {
    SinhVien a[MAX];
    int front;
    int rear;
};

void init(Queue& q) {
    q.front = 0;
    q.rear = -1;
}

bool isEmpty(Queue q) {
    return q.front > q.rear;
}

bool isFull(Queue q) {
    return q.rear == MAX - 1;
}

void enqueue(Queue& q, SinhVien sv) {
    if (isFull(q)) {
        cout << "Hang doi da day! Khong the them sinh vien.\n";
        return;
    }
    q.a[++q.rear] = sv;
    cout << "Da them sinh vien " << sv.hoTen << " vao hang doi.\n";
}

void dequeue(Queue& q) {
    if (isEmpty(q)) {
        cout << "Hang doi rong! Khong co sinh vien de xu ly.\n";
        return;
    }
    cout << "Dang xu ly ho so cho sinh vien: " << q.a[q.front].hoTen 
         << " (Ma: " << q.a[q.front].maSo << ")\n";
    q.front++;
}

void frontSV(Queue q) {
    if (isEmpty(q)) {
        cout << "Hang doi rong!\n";
        return;
    }
    cout << "Sinh vien dang cho o dau hang: " << q.a[q.front].hoTen 
         << " (Ma: " << q.a[q.front].maSo << ")\n";
}

void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Danh sach cho trong!\n";
        return;
    }
    cout << "--- DANH SACH SINH VIEN DANG CHO ---\n";
    for (int i = q.front; i <= q.rear; i++) {
        cout << i - q.front + 1 << ". Ma: " << q.a[i].maSo 
             << " - Ho ten: " << q.a[i].hoTen << "\n";
    }
}

int main() {
    Queue q;
    init(q);

    SinhVien sv1 = {"SV01", "Nguyen Van A"};
    SinhVien sv2 = {"SV02", "Tran Thi B"};

    enqueue(q, sv1);
    enqueue(q, sv2);

    cout << "\n";
    display(q);

    cout << "\n";
    dequeue(q);

    cout << "\n";
    display(q);

    return 0;
}