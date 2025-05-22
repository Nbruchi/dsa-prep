#include "hospital_system.h"

int main() {
    Patient* patientHead = nullptr;
    Doctor* doctorHead = nullptr;
    Appointment* appointmentHead = nullptr;
    
    int choice;
    
    while (true) {
        std::cout << "\n=== Ruhengeri Referal Hospital Management System ===\n";
        std::cout << "1. Register Patient\n";
        std::cout << "2. Register Doctor\n";
        std::cout << "3. Register Appointment\n";
        std::cout << "4. Display Patients\n";
        std::cout << "5. Display Doctors\n";
        std::cout << "6. Display Appointments\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice (1-7): ";
        
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                registerPatient(patientHead);
                break;
            case 2:
                registerDoctor(doctorHead);
                break;
            case 3:
                registerAppointment(appointmentHead, patientHead, doctorHead);
                break;
            case 4:
                displayPatients(patientHead);
                break;
            case 5:
                displayDoctors(doctorHead);
                break;
            case 6:
                displayAppointments(appointmentHead);
                break;
            case 7:
                cleanup(patientHead, doctorHead, appointmentHead);
                std::cout << "Thank you for using the system. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }
    
    return 0;
} 