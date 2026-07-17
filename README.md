# Custom-Data-Structures-Library-System

A console-based Library Management System built from scratch in C++ using custom-implemented, low-level data structures. This application showcases academic-grade implementation of self-balancing binary search trees (AVL Trees), circular queues, and dynamic singly linked lists.

> 🎓 **Academic Project:** This project was developed as a final project for the **Data Structures (DS)** course during my university studies to demonstrate the practical application and execution of custom data structures without relying on STL containers (except for standard I/O).

---

## 🔑 Admin Credentials
To access the management/administrator panel, use the following credentials when signing in:
* **Username:** `Admin`
* **Password:** `1101`

---

## 📂 Project Directory Structure

```text
Library-System/
├── README.md                 # Project documentation
├── main.cpp                  # Application entry point & Admin/User CLI Menus
├── Node.h                    # Custom Singly Linked List Node template
├── Queue.h                   # Custom Circular Queue template (Reservation System)
├── AVL-Tree.h                # Custom AVL Tree template (Self-balancing Search & Sort)
├── Book.h                    # Book class declaration
├── Book.cpp                  # Book class implementation & reservation logic
├── User.h                    # User class declaration
└── User.cpp                  # User class implementation & borrowing logic

```

---

## 🛠️ Deep Dive: Custom Data Structures Implemented

Instead of using standard library containers (STL), this project builds and manages memory for three critical structures:

### 1. Self-Balancing AVL Tree (`AVLTree<T>`)

Used for lightning-fast **searching** ($O(\log N)$ complexity) and **sorting** ($O(N)$ via Inorder Traversal) of Books and Users.

* **Auto-Balancing:** Implements Left-Left (LL), Right-Right (RR), Left-Right (LR), and Right-Left (RL) rotations during insertion based on calculated node balance factors.
* **Overloaded Operators:** Objects are inserted dynamically; sorting and comparison are governed by overloaded `<` and `>=` operators inside `Book` (by Title) and `User` (by Username).

### 2. Circular Queue (`Queue<T>`)

Manages the **Book Reservation System** with a fixed memory footprint (`MAX = 13`) using modulo arithmetic (`(rear + 1) % MAX`) to prevent memory drift.

* **FIFO Logic:** Ensures fair allocation of highly-requested books to users.
* **Priority Tracking:** Includes custom queue state tracking (`i`) to manage reservation expiration periods.

### 3. Singly Linked List (`Node<T>`)

Acts as the primary linear storage for the global database of users and books, as well as tracking the specific books currently borrowed by each individual user.

---

## ⚙️ Core System Logic & Business Rules

* **Fine and Penalty System:** Users are allowed to keep a book for **10 days**. If returned late, a penalty of **$5 per day** is calculated dynamically:

$$\text{Penalty} = (\text{Today} - \text{Assign Date} - 10) \times \$5$$


* **Automatic Reservation Expiration:** When an administrator checks a book's reservation status, the system automatically purges stale reservations if the user has failed to claim the book within a specified threshold (tracked via system days).
* **Double Authentication Roles:** Supports standard **User Sign-Up/Sign-In** and an **Admin Control Panel** secured via administrator credentials.

---

## 📊 Time Complexity Analysis

| Operation / Structure | Data Structure | Time Complexity (Best/Average) | Time Complexity (Worst) |
| --- | --- | --- | --- |
| **Search User/Book** | AVL Tree | $O(\log N)$ | $O(\log N)$ |
| **Sort / List Books** | AVL Tree | $O(N)$ (Inorder Traversal) | $O(N)$ |
| **Add Reservation** | Circular Queue | $O(1)$ | $O(1)$ |
| **Remove Reservation** | Circular Queue | $O(1)$ | $O(1)$ |
| **Insert Borrowed Book** | Linked List | $O(1)$ | $O(1)$ |

---

## 🚀 How to Compile and Run (Linux / GCC)

Compile all files using standard GCC with C++11 or higher:

```bash
# Compile the project
g++ -std=c++11 main.cpp Book.cpp User.cpp -o library_system

# Run the application
./library_system

```

---

## 💡 Key Technical Concepts Covered

* **Memory Management:** Manual allocation and deallocation (`new`/`delete`) of dynamic nodes to prevent memory leaks.
* **Template Programming:** Fully templated `Node`, `Queue`, and `AVLTree` classes to decouple data structures from domain entities (`Book` and `User`).
* **Operator Overloading:** Custom comparison behaviors allowing complex classes to interface seamlessly with standard search trees.

```

```
