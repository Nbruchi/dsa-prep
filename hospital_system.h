#ifndef HOSPITAL_SYSTEM_H
#define HOSPITAL_SYSTEM_H

#include <string>
#include <iostream>

// Patient structure
struct Patient {
    int patient_id;
    std::string name;
    std::string dob;
    std::string gender;
    Patient* next;
    
    Patient(int id, const std::string& n, const std::string& d, const std::string& g) 
        : patient_id(id), name(n), dob(d), gender(g), next(nullptr) {}
};

// Doctor structure
struct Doctor {
    int doctor_id;
    std::string name;
    std::string specialization;
    Doctor* next;
    
    Doctor(int id, const std::string& n, const std::string& s) 
        : doctor_id(id), name(n), specialization(s), next(nullptr) {}
};

// Appointment structure
struct Appointment {
    int appointment_id;
    int patient_id;
    int doctor_id;
    std::string appointment_date;
    Appointment* next;
    
    Appointment(int id, int p_id, int d_id, const std::string& date) 
        : appointment_id(id), patient_id(p_id), doctor_id(d_id), 
          appointment_date(date), next(nullptr) {}
};

// Function declarations
void registerPatient(Patient*& head);
void registerDoctor(Doctor*& head);
void registerAppointment(Appointment*& head, Patient* patientHead, Doctor* doctorHead);
void displayPatients(Patient* head);
void displayDoctors(Doctor* head);
void displayAppointments(Appointment* head);
bool isPatientExists(Patient* head, int id);
bool isDoctorExists(Doctor* head, int id);
bool isAppointmentExists(Appointment* head, int id);
void cleanup(Patient*& patientHead, Doctor*& doctorHead, Appointment*& appointmentHead);

#endif 