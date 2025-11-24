#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for Treatment Record
typedef struct {
    int treatmentID;
    int patientID;
    char patientName[50];
    char diagnosis[100];
    char medicines[100];
    char dosage[50];
    char duration[50];
    char doctorNotes[200];
} Treatment;

FILE *fp;

// Function prototypes
void addTreatment();
void viewTreatments();
void searchTreatment();
void updateTreatment();
void deleteTreatment();

int main() {
    int choice;

    // Open file in append+read mode, create if missing
    fp = fopen("treatments.dat", "ab+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (1) {
        printf("\n===== Treatment Management System =====\n");
        printf("1. Add Treatment\n");
        printf("2. View All Treatments\n");
        printf("3. Search Treatment\n");
        printf("4. Update Treatment\n");
        printf("5. Delete Treatment\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTreatment(); break;
            case 2: viewTreatments(); break;
            case 3: searchTreatment(); break;
            case 4: updateTreatment(); break;
            case 5: deleteTreatment(); break;
            case 6: fclose(fp); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to add a new treatment
void addTreatment() {
    Treatment t;
    printf("\nEnter Treatment ID: ");
    scanf("%d", &t.treatmentID);
    printf("Enter Patient ID: ");
    scanf("%d", &t.patientID);
    getchar(); // clear newline
    printf("Enter Patient Name: ");
    fgets(t.patientName, sizeof(t.patientName), stdin);
    t.patientName[strcspn(t.patientName, "\n")] = '\0';

    printf("Enter Diagnosis: ");
    fgets(t.diagnosis, sizeof(t.diagnosis), stdin);
    t.diagnosis[strcspn(t.diagnosis, "\n")] = '\0';

    printf("Enter Medicines: ");
    fgets(t.medicines, sizeof(t.medicines), stdin);
    t.medicines[strcspn(t.medicines, "\n")] = '\0';

    printf("Enter Dosage: ");
    fgets(t.dosage, sizeof(t.dosage), stdin);
    t.dosage[strcspn(t.dosage, "\n")] = '\0';

    printf("Enter Duration: ");
    fgets(t.duration, sizeof(t.duration), stdin);
    t.duration[strcspn(t.duration, "\n")] = '\0';

    printf("Enter Doctor Notes: ");
    fgets(t.doctorNotes, sizeof(t.doctorNotes), stdin);
    t.doctorNotes[strcspn(t.doctorNotes, "\n")] = '\0';

    fwrite(&t, sizeof(Treatment), 1, fp);
    printf("Treatment record added successfully!\n");
}

// Function to view all treatments
void viewTreatments() {
    rewind(fp);
    Treatment t;
    printf("\n--- All Treatments ---\n");
    while (fread(&t, sizeof(Treatment), 1, fp) == 1) {
        printf("Treatment ID: %d | Patient ID: %d | Name: %s\n", 
               t.treatmentID, t.patientID, t.patientName);
        printf("Diagnosis: %s | Medicines: %s | Dosage: %s | Duration: %s\n", 
               t.diagnosis, t.medicines, t.dosage, t.duration);
        printf("Doctor Notes: %s\n", t.doctorNotes);
        printf("---------------------------------------\n");
    }
}

// Function to search treatment by ID
void searchTreatment() {
    rewind(fp);
    Treatment t;
    int id, found = 0;
    printf("\nEnter Treatment ID to search: ");
    scanf("%d", &id);

    while (fread(&t, sizeof(Treatment), 1, fp) == 1) {
        if (t.treatmentID == id) {
            printf("Treatment Found!\n");
            printf("Patient Name: %s | Diagnosis: %s\n", t.patientName, t.diagnosis);
            found = 1;
            break;
        }
    }
    if (!found) printf("No treatment record found with ID %d\n", id);
}

// Function to update treatment
void updateTreatment() {
    rewind(fp);
    Treatment t;
    int id, found = 0;
    FILE *temp = fopen("temp.dat", "wb");

    printf("\nEnter Treatment ID to update: ");
    scanf("%d", &id);

    while (fread(&t, sizeof(Treatment), 1, fp) == 1) {
        if (t.treatmentID == id) {
            printf("Enter new Diagnosis: ");
            getchar();
            fgets(t.diagnosis, sizeof(t.diagnosis), stdin);
            t.diagnosis[strcspn(t.diagnosis, "\n")] = '\0';
            found = 1;
        }
        fwrite(&t, sizeof(Treatment), 1, temp);
    }
    fclose(fp);
    fclose(temp);
    remove("treatments.dat");
    rename("temp.dat", "treatments.dat");
    fp = fopen("treatments.dat", "ab+");

    if (found) printf("Treatment record updated successfully!\n");
    else printf("No record found with ID %d\n", id);
}

// Function to delete treatment
void deleteTreatment() {
    rewind(fp);
    Treatment t;
    int id, found = 0;
    FILE *temp = fopen("temp.dat", "wb");

    printf("\nEnter Treatment ID to delete: ");
    scanf("%d", &id);

    while (fread(&t, sizeof(Treatment), 1, fp) == 1) {
        if (t.treatmentID != id) {
            fwrite(&t, sizeof(Treatment), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fp);
    fclose(temp);
    remove("treatments.dat");
    rename("temp.dat", "treatments.dat");
    fp = fopen("treatments.dat", "ab+");

    if (found) printf("Treatment record deleted successfully!\n");
    else printf("No record found with ID %d\n", id);
}