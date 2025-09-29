using namespace vex;


// VEXcode devices

// Extern Brain
extern brain Brain;
// Extern Drivetrain
extern controller Controller1;
// Extern Drivetrain
extern smartdrive Drivetrain;
extern inertial DrivetrainInertial;
extern motor LeftDriveMotor1;
extern motor LeftDriveMotor2;
extern motor LeftDriveMotor3;
extern motor_group LeftDriveSmart;
extern motor RightDriveMotor1;
extern motor RightDriveMotor2;
extern motor RightDriveMotor3;
extern motor_group RightDriveSmart;
// Extern Intake Motors
extern motor Motor1;
extern motor Motor2;
extern motor Motor3;
extern distance Distance;
extern digital_out DigitalOutA;

void  vexcodeInit( void );
