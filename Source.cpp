#include "Functions.h"
#include "Student.h"
#include "Cart.h"
#ifndef CourseData
SoftwareCourses Software[MAX_SOFT] = { SoftwareCourses(39,90,90,33,14,1,1001,"Programming - I","T - 800","None",900000,40,"C","SOFT","Visual Studio 2022"),SoftwareCourses(58,90,49,25,14,2,2001,"Programming - II","T - 1000","SOFT1001",490000,32,"C","SOFT","GCC(editor depends on student preference)"),SoftwareCourses(69,120,107,48,21,3,3001,"Object Oriented Programming - I","HAL9000","None",1070000,58.5,"C++","SOFT","Visual Studio 2022"),SoftwareCourses(39,120,77,31,21,4,4001,"Object Oriented Programming - II","Bender Bending Rodrigez","SOFT3001",770000,41.5,"C++","SOFT","GCC(editor depends on student preference)"),SoftwareCourses(19,80,42,13,28,5,5001,".NET Development - I","Calculon","None",420000,27,"C#","SOFT","Visual Studio 2022"),SoftwareCourses(20,80,35,11,28,6,6001,".NET Development - II","Metal Sonic","SOFT5001",350000,25,"C#","SOFT","Visual Studio 2022"),SoftwareCourses(49,50,8,5,7,7,7001,"Scripting - I","WALL - E","None",80000,8.5,"Python","SOFT","Pycharm"),SoftwareCourses(12,30,15,4,14,7,7002,"Platform Independent Programming - I","Ultron","SOFT2001",150000,11,"Java","SOFT","Visual Studio 2022"),SoftwareCourses(7,20,18,5,14,7,7003,"Low Level Programming - I","GLaDOS","None",180000,12,"Assembly","SOFT","GNU Assembler"),SoftwareCourses(50,50,63,22,10,7,7004,"Website Development - I","Wheatley","None",630000,27,"HTML","SOFT","Student can Choose"),SoftwareCourses(12,20,22,7,16,7,7005,"Bash automation" ,"Rick Sanchez","SOFT7001",220000,15,"Bash","SOFT","UNIX - based OS recommended"),SoftwareCourses(19,20,14,6,16,7,7006,"Windows automation","Gordon Freeman","SOFT7001",140000,14,"Batch","SOFT","Windows"),SoftwareCourses(49,50,5,3,7,7,7101,"Scripting - II","Tony Stark","None",50000,6.5,"Python","SOFT","Student can Choose"),SoftwareCourses(42,60,53,24,14,7,7102,"Platform Independent Programming - II","Marcin Kleczynski","SOFT2001",530000,31,"Java","SOFT","Student can Choose"),SoftwareCourses(36,20,83,30,14,7,7103,"Low Level Programming - II","Masatoshi Shima","None",830000,37,"Assembly","SOFT","GNU Assembler"),SoftwareCourses(44,50,72,32,12,7,7104,"Website Development - II","Vision","None",720000,38,"HTML","SOFT","Student can Choose") };
LanguageCourses Language[MAX_LANG] = { LanguageCourses(21,40,38,16,14,1,1001,"English - I","Edna Mode","None",380000,23,"English","LANG",true),LanguageCourses(32,50,51,25,28,1,1002,"German - I","Optimus Prime","None",510000,39,"German","LANG",false),LanguageCourses(80,80,52,18,12,1,1003,"Turkish - I","Wednesday Adams","None",520000,24,"Turkish","LANG",false),LanguageCourses(20,40,8,5,20,2,2001,"English - II","Ethan Hunt","LANG1001",80000,15,"English","LANG",true),LanguageCourses(12,20,3,3,40,3,3001,"Russian - I","Ivan Vanko","None",30000,23,"Russian","LANG",true),LanguageCourses(19,20,43,18,10,3,3002,"Italian - I","Vito Corleone","None",430000,23,"Italian","LANG",true),LanguageCourses(5,80,1,1,10,3,3003,"Turkish - II","Arif Iþýk","LANG1003",10000,6,"Turkish","LANG",true) };
ProfessionalDevelopmentCourses Professional[MAX_PROF] = { ProfessionalDevelopmentCourses(37,40,69,32,18,5,5001,"Command Line Programs","Steve Ballmer","SOFT2001",690000,41,"Console Applications","PROF",true),ProfessionalDevelopmentCourses(34,50,76,28,18,5,5010,"Introduction to Automation","Jeff Bezos","SOFT2001",760000,37,"Unattended Applications","PROF",false),ProfessionalDevelopmentCourses(54,60,21,7,24,5,5020,"Network Administration","Mark Zuckerberg","SOFT4001",210000,19,"Network Management","PROF",false),ProfessionalDevelopmentCourses(11,30,10,5,24,5,5030,"File Types","Bill Gates","SOFT4001",100000,17,"File Structures","PROF",true),ProfessionalDevelopmentCourses(39,40,57,22,30,6,6001,"Storing Images","Jawed Karim","SOFT5001",570000,37,"Image Optimization","PROF",false),ProfessionalDevelopmentCourses(34,50,58,20,30,6,6002,"Parallel Processing","Alan Turing","SOFT4001",580000,35,"Multicore Programming","PROF",true),ProfessionalDevelopmentCourses(13,20,36,13,6,6,6010,"Designing UI","Steve Jobs","None",360000,16,"User Interfaces","PROF",true),ProfessionalDevelopmentCourses(19,40,6,5,12,6,6020,"Database Administration","Aaron Swartz","None",60000,11,"Database Management","PROF",true),ProfessionalDevelopmentCourses(21,40,31,16,12,7,7001,"Memory Management","Dave Plummer","SOFT2001",310000,22,"Memory Management","PROF",false),ProfessionalDevelopmentCourses(10,20,18,7,12,7,7002,"3D Graphics Calculation","Gabe Newell","None",180000,13,"3D Graphics","PROF",false),ProfessionalDevelopmentCourses(48,50,81,26,12,7,7010,"Compression Methods","Igor Pavlov","PROF5030",810000,32,"Compression Algorithms","PROF",false),ProfessionalDevelopmentCourses(51,60,41,18,18,7,7020,"Designing IO Devices","Steve Wozniak","SOFT4001",410000,27,"Input / Output Devices","PROF",true),ProfessionalDevelopmentCourses(20,70,32,17,6,8,8001,"Applications of Sensors","Satoru Iwata","PROF7020",320000,20,"Sensors","PROF",true),ProfessionalDevelopmentCourses(13,20,20,9,18,8,8011,"Cyber - Security","Eugene Kaspersky","None",200000,18,"Cyber - Security","PROF",true),ProfessionalDevelopmentCourses(44,50,108,39,18,8,8021,"Advanced Circuit Boards","Masatoshi Shima","None",1080000,48,"Board Design","PROF",true),ProfessionalDevelopmentCourses(19,50,23,8,12,8,8031,"Communicating Devices with Operating System","Dennis Ritchie","PROF7020",230000,14,"Drivers","PROF",false) };
Electives Elective[MAX_ELEC] = {};

#endif 


int main() {
	int EXIT_FLAG = -1,LoggedIn=-1;
	do
	{
		string warn;
		char choice = 127;
		string name = "", surname = "", mail = ""; 
		cout << "Enter Login Information\nName:\t\t";getline(cin, name);
		cout << "Surname:\t"; cin >> surname;
		cin.ignore();
		cout << "Mail Adress:\t"; cin >> mail;
		cin.ignore();
		Student User(name, surname, mail);
		Cart UserCart;
		cout << "\n\nWelcome " << User.getInfo("name") << " " << User.getInfo("surname") << "\nlogged in as \"" << User.getInfo("mail") << "\"\n";
		do
		{
			cout<<"Please Select a Choice\n1 : Change Information\n2 : List User Information\n3 : List Avalible Courses\n4 : Add Course to Cart\n5 : List Cart\n6 : Remove From Cart\n7 : Rate Registered Courses\n";
			cout << "\nl to log out\nq to Quit"<<endl;
			cin >> choice;
			fixChoice(&choice);
			switch (choice)
			{
			case '1': {
				do {
					cout << "Please Choose What Information to change\n1-User Name\n2-User Surname\n3-User Mail Adress\n4-Enter Payment Information";
					if (User.getInfo("enteredpayment") == "y")
						cout << " Again";
					cout << "\n5 - Go Back"; cin >> choice; cin.ignore(); fixChoice(&choice);
					switch (choice)
					{

					case '1': {
						do {
							cout << "Enter New User Name:"; getline(cin, name); cout << "Old Name \"" << User.getInfo("name") << "\"\nNew Name\"" << name << "\"\nConfirm Action(Y\\N)"; cin >> choice; fixChoice(&choice); cin.ignore();

							switch (choice)
							{
							case 'y':
								User.EnterInfo(1, name); break;
							case 'n':
								name = User.getInfo("name"); break;
							default:
								cout << "Please Select Yes or No\n";
								break;
							}
						} while (!(choice == 'y' || choice == 'n'));
					}choice = ChangeExitChar; break;
					case '2': {
						do {
							cout << "Enter New Surname:"; cin >> surname; cin.ignore(); cout << "Old Surname \"" << User.getInfo("surname") << "\"\nNew Surname\"" << surname << "\"\nConfirm Action(Y\\N)"; cin >> choice; fixChoice(&choice); cin.ignore();

							switch (choice)
							{
							case 'y':
								User.EnterInfo(2, surname); break;
							case 'n':
								mail = User.getInfo("surname"); break;
							default:
								cout << "Please Select Yes or No\n";
								break;
							}
						} while (!(choice == 'y' || choice == 'n'));
					}choice = ChangeExitChar; break;
					case '3': {
						do {
							cout << "Enter New Mail Adress:"; cin >> mail; cin.ignore(); cout << "Old Adress \"" << User.getInfo("mail") << "\"\nNew Adress\"" << mail << "\"\nConfirm Action(Y\\N)"; cin >> choice; fixChoice(&choice); cin.ignore();

							switch (choice)
							{
							case 'y':
								User.EnterInfo(3, mail); break;
							case 'n':
								mail = User.getInfo("mail"); break;
							default:
								cout << "Please Select Yes or No\n";
								break;
							}
						} while (!(choice == 'y' || choice == 'n'));
					}choice = ChangeExitChar; break;
					case '4': {
						cin >> User;
					}choice = ChangeExitChar; break;
					case ChangeExitChar: break;
					default:
					{
						cout << "Please Select a Information to Update\a\n";
						break;
					}
					}choice = ChangeExitChar; break;
				} while (choice != '5');
			}break;
			case '2': {
				cout << "User Name: " << User.getInfo("name") << "\nUser Surname: " << User.getInfo("surname") << "\nUser Mail: " << User.getInfo("mail") << endl;
				User.ListRegistered();
				UserCart.ViewCart();

			}break;
			case '3': {
				do {
					cout << "Select Course Category:\n1-Software Courses\n2-Language Courses\n3-Professional Development Courses\n4-Elective Courses\n5-Go Back" << endl; cin >> choice; cin.ignore(); fixChoice(&choice);
					switch (choice)
					{
					case '1': {
						for (int i = 0; i < MAX_SOFT; i++)
						{
							cout << "Course " << i+1 << " for Software\n";
							Software[i].displayInfo();
							cout << endl;
						}
					}choice = '5'; break;
					case '2': {
						for (int i = 0; i < MAX_LANG; i++)
						{
							cout << "Course " << i+1 << " for Language\n";
							Language[i].displayInfo();
							cout << endl;
						}
					}choice = '5'; break;
					case '3': {
						for (int i = 0; i < MAX_PROF; i++)
						{
							cout << "Course " << i+1 << " for Professional Development\n";
							Professional[i].displayInfo();
							cout << endl;
						}
					}choice = '5'; break;
					case '4': {
						for (int i = 0; i < MAX_ELEC; i++)
						{
							cout << "Course " << i+1 << " for Elective\n";
							Elective[i].displayInfo();
							cout << endl;
						}
					}choice = '5'; break;
					default:
						cout << "Selected Option \"" << choice << "\"Please Select A Supported Option\n";
						break;
					}
				} while (choice != '5');
			}break;
			case '4': {
				string wholeid="";
				string prefix="";
				int id = 0;
				cout << "Enter The ID of the Course : ";/* cin >>prefix; cin >>id;*/cin >>wholeid;
				for ( int i = 0;  i < wholeid.size();  i++)
				{//This whole part can be avoided if i divided the selection system.
					if (wholeid[i] >= '0' && wholeid[i] <= '9') {
						prefix = wholeid.substr(0, i);
						for (int j = i; j < wholeid.size(); j++)
						{
							if (wholeid[j] >= '0' && wholeid[j] <= '9') {
								id += (wholeid[j] - '0') *powof10(static_cast<int>(wholeid.size())-(j+1));
							}
						}
						break;
					}
					
				}
				
				OnlineCourse* search = findCourse(prefix, id);
				if (search==nullptr)
				{
					cout << "Can't Find Requested Course";
					break;
				}
				if (UserCart.CartInsert(search) != true) {
					cout << "Can't Add Requested Course";
					break;
				}
				cout << "Successfully added Course to the cart";
			}break;
			case '5': {
				UserCart.ViewCart();
				if (UserCart.CartStatus()!=0)
				{
					cout << "Would You Like To Finish Registering Process And Continue With Payment?\n[Y] Yes [N] No"; cin >> choice; cin.ignore(); fixChoice(&choice);
					if (choice != 'y')
						break;
					if(User.getInfo("enteredpayment") == "n")
						cin >> User;
					cout << "Entered Payment Info\n" << User;
					double tempprice = UserCart.PayPrice();
					if (UserCart.RegisterItems(User) == true) {
						printf("\nTotal Price of %.2F has been transactioned from your Cart", tempprice);
					}
					else {
						cout << "\nAn Error Occured,Payment Process is cancelled";
					}
				}
			}break;
			case '6': {
				int toremove = 0;
				UserCart.ViewCart();
				if (UserCart.CartStatus() == 0)
					break;
				cout << "Please Select Which Item You Want To Remove From Cart (1-" << ((UserCart.CartStatus()==-1)?3: UserCart.CartStatus()+1) << ") :"; cin >> toremove; cin.ignore();
				UserCart.RemoveCart(toremove);
			}break;
			case '7': {
				int torate = 0;
				if (User.RegisterStatus() == 0){
					User.ListRegistered();
					break;
				}else
					do{
						User.ListRegistered();
						cout << "Please Select Which Item You Want To Rate (1-" << ((User.RegisterStatus() == -1) ? 99 : User.RegisterStatus()) << ") (-1 to cancel):"; cin >> torate; cin.ignore();
						if (torate!=-1)
							if (User.getInfo(torate)==true)
							{
								cout << "\nCourse Already Rated!\nWould You like to change your rate? \n[Y] Yes - [N] No "; cin >> choice; fixChoice(&choice), cin.ignore();
								if (choice != 'y')
								{
									torate = -1;
									break;
								}
							}
					} while (!((torate <= ((User.RegisterStatus() == -1) ? 99 : User.RegisterStatus())) && (torate >= 1)));
				if(torate!=-1)
					User.rateCourse(torate);

			}break;
			case 'l':
			{
				cout << "You Choose To log out please enter \"logout\" exactly to log out:\n"; cin >> warn;
				if (warn!="logout")
				{
					cout << "Authentication failed!";
					choice = 0;
				}
				getline(cin,warn);
			}break;
			case 'q':
			{
				cout << "You Choose To Quit Program please enter \":q!\" exactly to  end the session:\n"; cin >> warn;
				
				if (warn == "howdoiexitvim") {
					cout << "Access granted!,Quitting";
					return 1;
				}
				else if (warn != ":q!")
				{
					cout << "Authentication failed!";
					choice = 0;
					break;
				}
			}EXIT_FLAG = 1; break;
			default:
				cout << "Selected Option \""<<choice<<"\"Please Select A Supported Option\n";
				break;
			}
		} while (!(choice =='l' || choice == 'q'));

	} while (EXIT_FLAG!=1);
	cout << "\nExiting!";
	return 0;
}