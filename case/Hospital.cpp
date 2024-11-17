#include <iostream>
#include <map>
#include <string>
using namespace std;

class Hospital {
private:
    struct Patient {
        string name;
        int age;
        string ailment;
    };
    struct Doctor {
        string name;
        string specialty;
    };
    map<int, Patient> patients;
    map<int, Doctor> doctors;
    map<int, int> appointments; // Maps patient ID to doctor ID

public:
    void addDoctor(int docID, string name, string specialty) {
        if (doctors.count(docID) == 0) {
            doctors[docID] = {name, specialty};
            cout << "Doctor added: " << name << " (Specialty: " << specialty << ")" << endl;
        } else {
            cout << "Doctor ID already exists!" << endl;
        }
    }

    void addPatient(int patientID, string name, int age, string ailment) {
        if (patients.count(patientID) == 0) {
            patients[patientID] = {name, age, ailment};
            cout << "Patient added: " << name << " (Age: " << age << ", Ailment: " << ailment << ")" << endl;
        } else {
            cout << "Patient ID already exists!" << endl;
        }
    }

    void bookAppointment(int patientID, int doctorID) {
        if (patients.count(patientID) && doctors.count(doctorID)) {
            appointments[patientID] = doctorID;
            cout << "Appointment booked for " << patients[patientID].name << " with Dr. " << doctors[doctorID].name << endl;
        } else {
            cout << "Invalid patient or doctor ID!" << endl;
        }
    }

    void viewAppointments() {
        cout << "Appointments:\n";
        for (const auto &entry : appointments) {
            int patientID = entry.first;
            int doctorID = entry.second;
            cout << patients[patientID].name << " -> Dr. " << doctors[doctorID].name << endl;
        }
    }
};

int main() {
    Hospital hospital;
    hospital.addDoctor(1, "Dr. Smith", "Cardiology");
    hospital.addDoctor(2, "Dr. Brown", "Orthopedics");

    hospital.addPatient(101, "Alice", 30, "Chest Pain");
    hospital.addPatient(102, "Bob", 45, "Knee Pain");

    hospital.bookAppointment(101, 1);
    hospital.bookAppointment(102, 2);

    hospital.viewAppointments();

    return 0;
}
