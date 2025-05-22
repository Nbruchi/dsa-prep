#include "hospital_system.h"
#include <limits>

void registerPatient(Patient*& head) {
    int id;
    std::string name, dob, gender;
    
    std::cout << "\nEnter Patient ID: ";
    std::cin >> id;
    
    if (isPatientExists(head, id)) {
        std::cout << "Error: Patient ID already exists!\n";
        return;
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Enter Patient Name: ";
    std::getline(std::cin, name);
    
    std::cout << "Enter Date of Birth (DD/MM/YYYY): ";
    std::getline(std::cin, dob);
    
    std::cout << "Enter Gender: ";
    std::getline(std::cin, gender);
    
    Patient* newPatient = new Patient(id, name, dob, gender);
    newPatient->next = head;
    head = newPatient;
    
    std::cout << "Patient registered successfully!\n";
}

void registerDoctor(Doctor*& head) {
    int id;
    std::string name, specialization;
    
    std::cout << "\nEnter Doctor ID: ";
    std::cin >> id;
    
    if (isDoctorExists(head, id)) {
        std::cout << "Error: Doctor ID already exists!\n";
        return;
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Enter Doctor Name: ";
    std::getline(std::cin, name);
    
    std::cout << "Enter Specialization: ";
    std::getline(std::cin, specialization);
    
    Doctor* newDoctor = new Doctor(id, name, specialization);
    newDoctor->next = head;
    head = newDoctor;
    
    std::cout << "Doctor registered successfully!\n";
}

void registerAppointment(Appointment*& head, Patient* patientHead, Doctor* doctorHead) {
    int appointment_id, patient_id, doctor_id;
    std::string date;
    
    std::cout << "\nEnter Appointment ID: ";
    std::cin >> appointment_id;
    
    if (isAppointmentExists(head, appointment_id)) {
        std::cout << "Error: Appointment ID already exists!\n";
        return;
    }
    
    std::cout << "Enter Patient ID: ";
    std::cin >> patient_id;
    
    if (!isPatientExists(patientHead, patient_id)) {
        std::cout << "Error: Patient ID does not exist!\n";
        return;
    }
    
    std::cout << "Enter Doctor ID: ";
    std::cin >> doctor_id;
    
    if (!isDoctorExists(doctorHead, doctor_id)) {
        std::cout << "Error: Doctor ID does not exist!\n";
        return;
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Enter Appointment Date (DD/MM/YYYY): ";
    std::getline(std::cin, date);
    
    Appointment* newAppointment = new Appointment(appointment_id, patient_id, doctor_id, date);
    newAppointment->next = head;
    head = newAppointment;
    
    std::cout << "Appointment registered successfully!\n";
}

void displayPatients(Patient* head) {
    if (!head) {
        std::cout << "\nNo patients registered.\n";
        return;
    }
    
    std::cout << "\nPatient List:\n";
    std::cout << "ID\tName\t\tDOB\t\tGender\n";
    std::cout << "----------------------------------------\n";
    
    Patient* current = head;
    while (current) {
        std::cout << current->patient_id << "\t"
                  << current->name << "\t\t"
                  << current->dob << "\t"
                  << current->gender << "\n";
        current = current->next;
    }
}

void displayDoctors(Doctor* head) {
    if (!head) {
        std::cout << "\nNo doctors registered.\n";
        return;
    }
    
    std::cout << "\nDoctor List:\n";
    std::cout << "ID\tName\t\tSpecialization\n";
    std::cout << "----------------------------------------\n";
    
    Doctor* current = head;
    while (current) {
        std::cout << current->doctor_id << "\t"
                  << current->name << "\t\t"
                  << current->specialization << "\n";
        current = current->next;
    }
}

void displayAppointments(Appointment* head) {
    if (!head) {
        std::cout << "\nNo appointments registered.\n";
        return;
    }
    
    std::cout << "\nAppointment List:\n";
    std::cout << "ID\tPatient ID\tDoctor ID\tDate\n";
    std::cout << "----------------------------------------\n";
    
    Appointment* current = head;
    while (current) {
        std::cout << current->appointment_id << "\t"
                  << current->patient_id << "\t\t"
                  << current->doctor_id << "\t\t"
                  << current->appointment_date << "\n";
        current = current->next;
    }
}

bool isPatientExists(Patient* head, int id) {
    Patient* current = head;
    while (current) {
        if (current->patient_id == id) return true;
        current = current->next;
    }
    return false;
}

bool isDoctorExists(Doctor* head, int id) {
    Doctor* current = head;
    while (current) {
        if (current->doctor_id == id) return true;
        current = current->next;
    }
    return false;
}

bool isAppointmentExists(Appointment* head, int id) {
    Appointment* current = head;
    while (current) {
        if (current->appointment_id == id) return true;
        current = current->next;
    }
    return false;
}

void cleanup(Patient*& patientHead, Doctor*& doctorHead, Appointment*& appointmentHead) {
    // Cleanup patients
    while (patientHead) {
        Patient* temp = patientHead;
        patientHead = patientHead->next;
        delete temp;
    }
    
    // Cleanup doctors
    while (doctorHead) {
        Doctor* temp = doctorHead;
        doctorHead = doctorHead->next;
        delete temp;
    }
    
    // Cleanup appointments
    while (appointmentHead) {
        Appointment* temp = appointmentHead;
        appointmentHead = appointmentHead->next;
        delete temp;
    }
} 