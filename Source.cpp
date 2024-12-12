#include "Cart.h"//since Cart.h already includes everything used i only included cart.h
int main() {//main function
	//Course Data
	//there are some courses with registered students more than the course capacity itself to check the course full conditions and some of them are left with nearly full to test multiple students updating the data of course and the course will be locked to new students after a few student account registers the course
	//example= 30 people in 20 capacity course will tell its full and decline the process
	//example 2= 30 people in 32 capacity course user can still register but after user logsout and another user logsin and registers the count will be 32 and the course will not accept any more students
	//so student1 logins->selects courseA->registers->logsout The people count is now 31
	//then student2 logins->selects courseA->registers->logsout The people count is now 32(full)
	//then student3 logins->selects courseA->tries to register->Fails since course is full
	 SoftwareCourses Software[CURRENT_SOFT] = { SoftwareCourses(120,90,99,33,14,1,1001,"Programming - I","T-800","None",990000,40,"C","SOFT","Visual Studio 2022"),SoftwareCourses(58,90,62,25,14,2,2001,"Programming - II","T-1000","SOFT1001",620000,32,"C","SOFT","GCC (editor depends on student preference)"),SoftwareCourses(69,120,142,48,21,3,3001,"Object Oriented Programming - I","HAL9000","None",1420000,58.5,"C++","SOFT","Visual Studio 2022"),SoftwareCourses(39,120,84,31,21,4,4001,"Object Oriented Programming - II","Bender Bending Rodrigez","SOFT3001",840000,41.5,"C++","SOFT","GCC (editor depends on student preference)"),SoftwareCourses(19,80,47,13,28,5,5001,".NET Development - I","Calculon","None",470000,27,"C#","SOFT","Visual Studio 2022"),SoftwareCourses(20,80,41,11,28,6,6001,".NET Development - II","Metal Sonic","SOFT5001",410000,25,"C#","SOFT","Visual Studio 2022"),SoftwareCourses(49,50,17,5,7,7,7001,"Scripting - I","WALL-E","None",170000,8.5,"Python","SOFT","Pycharm"),SoftwareCourses(42,30,17,4,14,7,7002,"Platform Independent Programming - I","Ultron","SOFT2001",170000,11,"Java","SOFT","Visual Studio 2022"),SoftwareCourses(7,20,16,5,14,7,7003,"Low Level Programming - I","GLaDOS","None",160000,12,"Assembly","SOFT","GNU Assembler"),SoftwareCourses(50,50,76,22,10,7,7004,"Website Development - I","Wheatley","None",760000,27,"HTML","SOFT","Student can Choose"),SoftwareCourses(19,20,22,7,16,7,7005,"Bash automation ","Rick Sanchez","SOFT7001",220000,15,"Bash","SOFT","UNIX-based OS recommended"),SoftwareCourses(19,20,25,6,16,7,7006,"Windows automation","Gordon Freeman","SOFT7001",250000,14,"Batch","SOFT","Windows"),SoftwareCourses(49,50,11,3,7,7,7101,"Scripting - II","Tony Stark","None",110000,6.5,"Python","SOFT","Student can Choose"),SoftwareCourses(42,60,68,24,14,7,7102,"Platform Independent Programming - II","Eugene Kaspersky","SOFT2001",680000,31,"Java","SOFT","Student can Choose"),SoftwareCourses(36,20,97,30,14,7,7103,"Low Level Programming - II","Masatoshi Shima","None",970000,37,"Assembly","SOFT","GNU Assembler"),SoftwareCourses(44,50,96,32,12,7,7104,"Website Development -II","Vision","None",960000,38,"HTML","SOFT","Student can Choose") };
	 LanguageCourses Language[CUURENT_LANG] = { LanguageCourses(82,40,45,16,14,1,1001,"English - I","Edna Mode","None",450000,23,"English","LANG",true),LanguageCourses(32,50,77,25,28,1,1002,"German - I","Optimus Prime","None",770000,39,"German","LANG",false),LanguageCourses(80,80,57,18,12,1,1003,"Turkish - I","Wednesday Adams","None",570000,24,"Turkish","LANG",false),LanguageCourses(20,40,13,5,20,2,2001,"English - II","Ethan Hunt","LANG1001",130000,15,"English","LANG",true),LanguageCourses(12,20,10,3,40,3,3001,"Russian - I","Ivan Vanko","None",100000,23,"Russian","LANG",true),LanguageCourses(19,20,53,18,10,3,3002,"Italian - I","Vito Corleone","None",530000,23,"Italian","LANG",true),LanguageCourses(8,80,2,1,10,3,3003,"Turkish - II","Arif Isik","LANG1003",20000,6,"Turkish","LANG",true) };
	 ProfessionalDevelopmentCourses Professional[CURRENT_PROF] = { ProfessionalDevelopmentCourses(44,40,104,32,18,5,5001,"Command Line Programs","Steve Ballmer","SOFT2001",1040000,41,"Console Application","PROF",true),ProfessionalDevelopmentCourses(34,50,72,27,18,5,5010,"Introduction to Automation","Jeff Bezos","SOFT2001",720000,36,"Unattended Applications","PROF",false),ProfessionalDevelopmentCourses(54,60,20,7,24,5,5020,"Network Administration","Mark Zuckerberg","SOFT4001",200000,19,"Network Management","PROF",false),ProfessionalDevelopmentCourses(11,30,18,5,24,5,5030,"File Types","Bill Gates","SOFT4001",180000,17,"File Structures","PROF",true),ProfessionalDevelopmentCourses(39,40,60,22,30,6,6001,"Storing Images","Jawed Karim","SOFT5001",600000,37,"Image Optimization","PROF",false),ProfessionalDevelopmentCourses(34,50,55,20,30,6,6002,"Parallel Processing","Alan Turing","SOFT4001",550000,35,"Multicore Programming","PROF",true),ProfessionalDevelopmentCourses(13,20,37,13,6,6,6010,"Designing UI","Steve Jobs","None",370000,16,"User Interfaces","PROF",true),ProfessionalDevelopmentCourses(19,40,14,5,12,6,6020,"Database Administration","Aaron Swartz","None",140000,11,"Database Management","PROF",true),ProfessionalDevelopmentCourses(21,40,48,16,12,7,7001,"Memory Management","Dave Plummer","SOFT2001",480000,22,"Memory Management","PROF",false),ProfessionalDevelopmentCourses(30,20,17,7,12,7,7002,"3D Graphics Calculation","Gabe Newell","None",170000,13,"3D Graphics","PROF",false),ProfessionalDevelopmentCourses(48,50,78,26,12,7,7010,"Compression Methods","Igor Pavlov","PROF5030",780000,32,"Compression Algorithms","PROF",false),ProfessionalDevelopmentCourses(51,60,50,18,18,7,7020,"Designing IO Devices","Steve Wozniak","SOFT4001",500000,27,"Input/Output Devices","PROF",true),ProfessionalDevelopmentCourses(20,70,51,17,6,8,8001,"Applications of Sensors","Satoru Iwata","PROF7020",510000,20,"Sensors","PROF",true),ProfessionalDevelopmentCourses(13,20,28,9,18,8,8011,"Cyber-Security","Eugene Kaspersky","None",280000,18,"Cyber-Security","PROF",true),ProfessionalDevelopmentCourses(44,50,107,39,18,8,8021,"Advanced Circuit Boards","Masatoshi Shima","None",1070000,48,"Board Design","PROF",true),ProfessionalDevelopmentCourses(19,50,25,8,12,8,8031,"Communicating Devices with Operating System","Dennis Ritchie","PROF7020",250000,14,"Drivers","PROF",false) };
	 Electives Elective[CURRENT_ELEC] = { Electives(14,50,20,6,13,0,0001,"Society and Gender","George Michael","None",200000,12.5,"Psychology","PSKU",false),Electives(12,50,41,12,12,0,0001,"ADVENTURE OF FORM I","Roberta Flack","None",410000,18,"Architecture","MIMU",false),Electives(13,15,26,8,14,0,0004,"Life Culture","Bonnie Tyler","None",260000,15,"Communication Arts","ISNU",false),Electives(23,25,46,16,9,0,0005,"Entrepreneurship I","Frankie Valli","None",460000,20.5,"Business Administration","ISLU",false),Electives(19,25,49,16,11,0,0006,"Painting","Laura Branigan","None",490000,21.5,"Communication Designs - Multimedia","ITMU",false),Electives(14,40,23,7,13,0,0007,"Sculpture","Michael Buble","None",230000,13.5,"Communication Designs - Multimedia","ITMU",false),Electives(30,35,27,10,9,0,8,"Civilizations in History","Bruno Mars","None",270000,14.5,"International Relations","IRDU",false),Electives(30,40,90,28,8,0,80,"Literature. Media and Politics","George Thorogood","None",900000,32,"International Relations","IRDU",false),Electives(21,40,29,8,8,0,0401,"Special Topics in Computer Engineering","Michael Jackson","Basic IT and programming knowledge. basics of an operational world.",290000,12,"","COM",true),Electives(26,30,35,13,12,0,0403,"Special Topic in Artificial Intelligence","Freddie Mercury","None",350000,19,"","COM",true),Electives(12,25,19,5,12,0,0405,"Co-op Practice","Brian May","None",190000,11,"","COM",true),Electives(14,20,17,5,10,0,0412,"Data Warehouses and Data Mining","John Deacon","None",170000,10,"","COM",true),Electives(22,30,28,11,8,0,0416,"Game Programming","Gloria Gaynor","None",280000,15,"","SEN",true),Electives(11,40,25,8,13,0,840,"Advanced Logic Design","Lena Raine","None",250000,14.5,"","EE",true),Electives(12,30,21,6,14,1,1003,"Calculus - III","Sade Adu","None",210000,13,"","MCB",true),Electives(22,50,31,10,14,3,3202,"Logic Design","Pharrell Williams","None",310000,17,"","EE",true) };;
	int EXIT_FLAG = -1;//exit flag probably remove later
	do//program loop
	{
		string warn;//for authentication before doing any destructive process
		char choice = 127;//menu selector
		string name = "", surname = "", mail = ""; //user data
		cout << "Enter Login Information\nName:\t\t";getline(cin, name);
		cout << "Surname:\t"; cin >> surname;
		cin.ignore();//newline character ignore
		cout << "Mail Adress:\t"; cin >> mail;
		cin.ignore();//newline character ignore
		Student User(name, surname, mail);//student object creation
		Cart UserCart;//user object creation
		cout << "\n\nWelcome " << User.getInfo("name") << " " << User.getInfo("surname") << "\nlogged in as \"" << User.getInfo("mail") << "\"\n";//user greeting
		do//main menu loop
		{
			cout<<"\nPlease Select a Choice\n1 : Change Information\n2 : List User Information\n3 : List Avalible Courses\n4 : Add Course to Cart\n5 : List Cart\n6 : Remove From Cart\n7 : Rate Registered Courses\n";//prompt
			cout << "\nl to log out\nq to Quit"<<endl;
			cin >> choice;
			fixChoice(&choice);//to make case selection easier
			switch (choice)
			{
			case '1': {
				do {
					cout << "Please Choose What Information to change\n1-User Name\n2-User Surname\n3-User Mail Adress\n4-"<<((User.getInfo("enteredpayment")=="y")?"Change":"Enter")<<" Payment Information\n"<<ChangeExitChar<<" - Go Back"; cin >> choice; cin.ignore(); fixChoice(&choice);//prompt
					switch (choice)//this whole part is just get variable from object, display that variable, get input from user ,ask user if they are sure , then set the variable of the object with the input from user except credit card info it just overrides old one like apple id payment methods (i mistakenly reset payment method too many times when i was a kid).
					{
					case '1': {
						cout << "Enter New User Name:"; getline(cin, name);
						do {
							cout << "Old Name \"" << User.getInfo("name") << "\"\nNew Name\"" << name << "\"\nConfirm Action(Y\\N)"; cin >> choice; fixChoice(&choice); cin.ignore();
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
						cout << "Enter New Surname:"; getline(cin, surname);
						do {
							 cout << "Old Surname \"" << User.getInfo("surname") << "\"\nNew Surname\"" << surname << "\"\nConfirm Action(Y\\N)"; cin >> choice; fixChoice(&choice); cin.ignore();

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
						cout << "Enter New Mail Adress:"; getline(cin, mail);
						do {
							 cout << "Old Adress \"" << User.getInfo("mail") << "\"\nNew Adress\"" << mail << "\"\nConfirm Action(Y\\N)"; cin >> choice; fixChoice(&choice); cin.ignore();

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
					{//warn user that they failed choosing
						cout << "Please Select a Information to Update\a\n";
						break;
					}
					}
				} while (choice != ChangeExitChar);
			}break;
			case '2': {
				//user info with regiistered items and items in cart
				cout << "User Name: " << User.getInfo("name") << "\nUser Surname: " << User.getInfo("surname") << "\nUser Mail: " << User.getInfo("mail") << endl;
				User.ListRegistered();
				UserCart.ViewCart();

			}break;
			case '3': {
				do {//list courses
					cout << "Select Course Category:\n1-Software Courses\n2-Language Courses\n3-Professional Development Courses\n4-Elective Courses\n5-Go Back" << endl; cin >> choice; cin.ignore(); fixChoice(&choice);//get input
					switch (choice)
					{
					case '1': {//list software
						for (int i = 0; i < CURRENT_SOFT; i++)
						{
							cout << "Course " << i+1 << " for Software\n";
							Software[i].displayInfo();
							cout << endl;
						}
					}choice = '5'; break;//setting choice to choice to go back to main menu
					case '2': {//list language
						for (int i = 0; i < CUURENT_LANG; i++)
						{
							cout << "Course " << i+1 << " for Language\n";
							Language[i].displayInfo();
							cout << endl;
						}
					}choice = '5'; break;
					case '3': {//list professional development
						for (int i = 0; i < CURRENT_PROF; i++)
						{
							cout << "Course " << i+1 << " for Professional Development\n";
							Professional[i].displayInfo();
							cout << endl;
						}
					}choice = '5'; break;
					case '4': {//list electives
						for (int i = 0; i < CURRENT_ELEC; i++)
						{
							cout << "Course " << i+1 << " for Elective\n";
							Elective[i].displayInfo();
							cout << endl;
						}
					}choice = '5'; break;//exit
					default:
						cout << "Selected Option \"" << choice << "\"Please Select A Supported Option\n";
						break;
					}
				} while (choice != '5');
			}break;
			case '4': {
				string wholeid="";//to store the whole id
				string prefix="";//to store seperated prefix
				int id = 0;//tp store seperated id
				cout << "Enter The ID of the Course : ";
				cin.ignore();getline(cin, wholeid);
				for ( int i = 0;  i < wholeid.size();  i++)
				{//This whole part can be avoided if i divided the selection system.
					if (wholeid[i] >= '0' && wholeid[i] <= '9') {//search for numbers
						prefix = wholeid.substr(0, i);//set the seperated prefix variable to substring of whole id (from beginning of the id untill the numbers start/prefix ends)
						for (int j = i; j < wholeid.size(); j++)//continue a seperate loop
						{
							if (wholeid[j] >= '0' && wholeid[j] <= '9') {//now only get numbers
								id += (wholeid[j] - '0') *powof10(static_cast<int>(wholeid.size())-(j+1));
								/*
								since numbers are read from left to right but the values increase from right to left
								i made a power of 10 function
								which essentially takes the size of string
								for example
								"TEST1234"		1   2   3   4   5   6   7   8  
								The string is {'T','E','S','T','1','2','3','4'}
												0   1   2   3   4   5   6   7 
								the numbers start at index 4 
								the total length of the string is 9
								8-4=4 1*10^4=10000*1=10000 which is wrong
								arrays start from 0 we need to increase index by 1
								8-5=3 1*10^3=1000*1=1000 which is correct	| if we have a integer variable number; increasing number with this value will result in 1000 if the number is 0
								8-6=2 2*10^2=100 *2=200						| then 1000+200=1200
								8-7=1 3*10^1=10	 *3=30						| 1200+30=1230
								8-8=0 4*10^0=1	 *4=4						| 1230+4=1234

								the integer id part is now 1234
								*/
							}
						}
						break;
					}
					
				}
				//calling template function for the search function with prefix and id we calculated earlier and giving it a area to search (the object array adress and the size of the array(member count ,not byte count))
				OnlineCourse* search2 = findCourse2<SoftwareCourses>(prefix, id, Software, CURRENT_SOFT);
				if(search2==nullptr)
				search2 = findCourse2<LanguageCourses>(prefix, id, Language, CUURENT_LANG);
				if (search2 == nullptr)
				search2 = findCourse2<Electives>(prefix, id, Elective, CURRENT_ELEC);
				if (search2 == nullptr)
				search2 = findCourse2<ProfessionalDevelopmentCourses>(prefix, id, Professional, CURRENT_PROF);
				if(search2 == nullptr)
				{
					cout << "Can't Find Requested Course";
					break;
				}
				if (UserCart.CartInsert(search2) != true) {
					cout << "Can't Add Requested Course";
					break;
				}
				cout << "Successfully added Course to the cart";
			}break;
			case '5': {
				//will print out the cart information and handle payment process if user wants to
				UserCart.ViewCart();
				if (UserCart.CartStatus()!=0)
				{
					cout << "Would You Like To Finish Registering Process And Continue With Payment?"<<((User.getInfo("enteredpayment")=="y")?" (This Will Use Your Already Configured Payment Method":"") << "\n[Y] Yes - [N] No "; cin >> choice; cin.ignore(); fixChoice(&choice);
					if (choice != 'y')
						break;
					if(User.getInfo("enteredpayment") == "n")
						cin >> User;
					cout << "Entered Payment Info\n" << User;
					double tempprice = UserCart.PayPrice();//payprice returns the calculated price of the cart
					if (UserCart.RegisterItems(User) == true) {
						printf("\nTotal Price of %.2F has been transactioned from your Cart", tempprice);
					}
					else {
						cout << "\nAn Error Occured,Payment Process is cancelled";
					}
				}
			}break;
			case '6': {//prints out the list of cart items and asks user to which one to remove
				int toremove = 0;
				UserCart.ViewCart();
				if (UserCart.CartStatus() == 0)
					break;
				cout << "Please Select Which Item You Want To Remove From Cart (1-" << ((UserCart.CartStatus()==-1)?MAX_CART: UserCart.CartStatus()) << ") :"; cin >> toremove; cin.ignore();
				UserCart.RemoveCart(toremove);
			}break;
			case '7': {//prints out registered courses and asks user to which one to rate
				int torate = 0;
				User.ListRegistered();
				if (User.RegisterStatus() == 0)//if not registered to any course returns to main menu
					break;
				cout << "Please Select Which Item You Want To Rate (1-" << ((User.RegisterStatus() == -1) ? MAX_REGISTER : User.RegisterStatus()) << ") :"; cin >> torate; cin.ignore();
				if (User.getInfo(torate) == true){
					cout << "\nCourse Already Rated!\nWould You like to change your rate? \n[Y] Yes - [N] No "; cin >> choice; fixChoice(&choice), cin.ignore();
					if (choice != 'y'){
						torate = -1;
						break;
					}
				}
				User.rateCourse(torate);//handles both adding a new rate and updating existing rate
			}break;
			case 'l':
			{
				cout << "You Choose To log out please enter \"logout\" exactly to log out:\n"; cin >> warn;//warns user since logging out will delete their data from the program (saving to files not implemented yet)
				if (warn!="logout")//if user fails to enter security code
				{
					cout << "Authentication failed!";
					choice = 0;//they get sent back to the 
				}
				getline(cin,warn);//to clear the newline(i sincerely dont remeber but using cin.ignore failed miserably)
			}break;
			case 'q':
			{
				cout << "You Choose To Quit Program please enter \":q!\" exactly to end the session:\n"; cin >> warn;//warns user since Quitting will delete their data from the program (saving to files not implemented yet)
				
				if (warn == "howdoiexitvim") {//pure joke 
					cout << "Access granted!,Quitting";//you get access to quit
					return 1;
				}
				else if (warn != ":q!")//joke but practical
				{
					cout << "Authentication failed!";
					choice = 0;
					break;
				}
			}
			EXIT_FLAG = 1; break;
			default:
				cout << "\aSelected Option \""<<choice<<"\"Please Select A Supported Option\n";//warn user
				break;
			}
		} while (!(choice =='l' || choice == 'q'));//end loop contidion for logout or quit

	} while (EXIT_FLAG!=1);//end loop condition for quit
	cout << "\nExiting!";//goodbye message
	return 0;//return 0 successfully
}