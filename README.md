# SDLC Component Management System 💻

This project is part of the **Design Specification Report (DSR)** for the **Software Development Life Cycle (SDLC) Lab**. It provides a terminal-based system to **manage electronic component data** stored in a CSV file.

---

## 🔍 Project Objectives

- Create a DSR for SDLC Lab.
- Access, add, and manage data for electronic components in the lab.
- Ensure role-based access (admin and user).
- Read/write data from a `.csv` file derived from Excel.

---

## 📁 Features

- **Admin Access**:
  - Add new components to the system.
  - Search and view existing components.
  
- **User Access**:
  - View/search component data only (read-only access).
  
- **Component Details Include**:
  - Name
  - Value
  - Quantity
  - Unit

---

## 🔐 Access Keys

| Role   | Key              |
|--------|------------------|
| Admin  | `EED_SDLCadmin`  |
| User   | `EED_SDLCuser`   |

---

## 🛠️ Technologies Used

- C++
- File I/O with CSV
- Object-Oriented Programming (OOP)
- Terminal-based UI (using `cin` / `cout`)

---

## 📂 File Structure

```text
CPP_SDLC_PROJECT/
├── sdlc.csv                   # CSV file storing component data
├── main.cpp                   # Source code (this project)
└── README.md                  # This file
