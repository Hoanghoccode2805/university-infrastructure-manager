# Système de Gestion d'Infrastructure Universitaire (C++)
Projet de Programmation Orientée Objet (C++) modélisant l'infrastructure d'une université. Mise en œuvre d'une hiérarchie de classes, gestion dynamique de la mémoire et surcharge d'opérateurs. Réalisé dans le bản cadre de la formation d'ingénieur à l'INSA Centre Val de Loire.


# **Project Overview**
  This project is a high-level C++ application designed to model and manage the infrastructure of a university building. Developed as part of the Object-Oriented Programming (OOP) curriculum at INSA Centre Val de      Loire, the system manages rooms, specialized teaching facilities, offices, and staff members within a hierarchical architecture.

	
# **Technical Highlights**
  The project demonstrates mastery of several core C++ and OOP concepts:

    + Complex Class Hierarchy: Implemented inheritance to differentiate between standard rooms, teaching rooms (equipped with projectors), and administrative offices.
    + Encapsulation & Data Integrity: Used strict access modifiers to ensure attributes remain immutable once objects are instantiated, mimicking real-world architectural constraints.
    + Dynamic Memory Management: Utilized dynamic arrays to handle variable numbers of staff members per office and rooms per building.
    + Advanced Operator Overloading:
        operator[]: For intuitive, direct access to staff members within an office.
        operator<<: Custom stream insertion for comprehensive, formatted text output of all building entities.

				
# **Project Structure**
    File and Description

      main.cpp: Entry point of the application for testing and demonstration.
      batiment.hpp/cpp: Container class managing the global building infrastructure.
      salle.hpp/cpp: "Base class defining general room properties (name, area)."
      bureau.hpp/cpp: Specialized room for staff members with dynamic storage.
      personnel.hpp/cpp: Data structure for university staff (Teaching/Admin).
