/* CREATING FILE WHEN THERE IS NO INITIAL FILE*/
void check_file_created();
/* INITIALIZING ARRAY OF ROOM AND REASSIGN PREVIOUS BOOKING INTO ARRAY*/
void initialize_block();
void reassign_previous_booking();
/* INITIAL REGISTRATION AND BOOKING / CHOOSING ROOM */
int student_registration();
void male_booking_menu();
void female_booking_menu();
int gym_calculation();
int laundry_calculation();
int a1room_visuals();               
int a2room_visuals();               
int b1room_visuals();              
int b3room_visuals();               
/* STUDENT LOGIN TO CHANGE OR CANCEL ROOM, ADD SERVICE , CHECK DETAILS, MAKE PAYMENT AND EXIT TO MAIN MENU*/
int student_login();
void change_room();
void cancel_room();
void add_service();
int student_details();
void payment_facility();
/* ADMIN LOGIN, CHECK ROOM AVAILABLE, CHECK AMOUNT RECEIVABLE AND RELAVANT DETAILS*/
void admin_login();
void admin_system();
void check_r_available_and_m_receivables();
void check_block_student();
void search_student();
void check_room_availability();
/* COUNT ROOM AVAILABLE */
int a1_room_available();
int a2_room_available();
int b1_room_available();
int b3_room_available();
/* CALCULATE STUDENT'S PERSONAL DUE AMOUNT */
int personal_due(int rental, int gym, int laundry, int week_stay, int paid_amount);
/* EXIT PROGRAM */
void exitProgram();

/* CREATING DATA STRUCTURE FOR STUDENT, ONE FOR CHECKING ANOTHER FOR APPLYING*/
struct student {
	char studentID[10];
	char firstName[30];
	char lastName[30];
	char gender[2];
	char identification[15];
	int age;
	char phone_num[20];
	char email[50];
	char block_area[3];
	int room_num;
	int laundry_service;
	int gym_service;
	int week_stay;
	int amount_due;
	int paid_amount;
	int bed_num;
}apply, check;

/* INITIALIZING THE ARRAY FOR ROOMS AND BEDS */
int block_a1[100];
int block_a2[100][2];
int block_b1[100];
int block_b3[100][3];