# Data Structure Project - Restaurant Management System

A C++ console application that demonstrates custom data structure implementations through a restaurant management system.

## Project Overview

This application provides four management screens:

- **Menu Screen** — View, search by index, search by name, and clear a menu of food items (backed by a dynamic array)
- **Customer Screen** — Add default customers, add a single customer, print the queue, and serve (FIFO via queue)
- **Inventory Screen** — Add custom items and print the full inventory list (stored in a doubly linked list)
- **Order Screen** — Place, process, and print orders (FIFO via queue)

## Data Structures

All three structures are implemented as C++ templates and support any data type.

| Class | File | Description |
|---|---|---|
| `clsDynamicArray<T>` | `clsMyDynamicArray.h` | Resizable array with insert, delete, find, reverse, resize, and item access operations |
| `clsDblLinkedList<T>` | `clsDblLinkedList.h` | Doubly linked list with head/tail navigation; supports insert at beginning/end/after, delete by node/first/last, find, and indexed access |
| `clsMyQueue<T>` | `clsMyQueue.h` | Queue (FIFO) built on top of `clsDblLinkedList`; supports push, pop, front, back, and indexed item access |

## Custom Data Structure APIs

### clsDynamicArray<T>
| Method | Description |
|---|---|
| `SetItem(index, value)` | Set value at index |
| `GetItem(index)` | Get value at index |
| `Resize(newSize)` | Resize the array |
| `Find(value)` | Find index of a value (-1 if not found) |
| `InsertAt(index, value)` | Insert value at index |
| `InsertAtBeginnging(value)` | Insert at position 0 |
| `InsertAtEnd(value)` | Append at end |
| `DeleteItemAt(index)` | Remove item at index |
| `DeleteItem(value)` | Remove first occurrence of value |
| `Reverse()` | Reverse all elements |
| `Clear()` | Remove all elements |
| `Size()` | Return element count |
| `IsEmpty()` | Check if empty |

### clsDblLinkedList<T>
| Method | Description |
|---|---|
| `InsertAtBeginning(value)` | Insert at head |
| `InsertAtEnd(value)` | Append at tail |
| `InsertAfter(node, value)` | Insert after a given node |
| `InsertAfter(index, value)` | Insert after a given index |
| `DeleteNode(node)` | Delete a specific node |
| `DeleteFirstNode()` | Delete head |
| `DeleteLastNode()` | Delete tail |
| `Find(value)` | Find node by value |
| `GetNode(index)` | Get node at index |
| `GetItem(index)` | Get value at index |
| `UpdateItem(index, value)` | Update value at index |
| `Clear()` | Remove all nodes |
| `Size()` | Return node count |
| `IsEmpty()` | Check if empty |

### clsMyQueue<T>
| Method | Description |
|---|---|
| `push(value)` | Enqueue (insert at end) |
| `pop()` | Dequeue (remove from front) |
| `front()` | Peek at first element |
| `back()` | Peek at last element |
| `GetItem(index)` | Access item by index |
| `Size()` | Return element count |
| `IsEmpty()` | Check if empty |
| `Clear()` | Remove all elements |

## Build

This is a Visual Studio 2022 C++ project. Open `DataStructureProJect.sln` or the `.vcxproj` file and build for x64.

## Requirements

- Visual Studio 2022 (or compatible C++17 compiler)
- Windows SDK
