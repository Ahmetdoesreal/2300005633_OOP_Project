

#include "Cart.h"
#include "CourseData.h"
int main() {
	int EXIT_FLAG = -1;
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
			cout<<"\nPlease Select a Choice\n1 : Change Information\n2 : List User Information\n3 : List Avalible Courses\n4 : Add Course to Cart\n5 : List Cart\n6 : Remove From Cart\n7 : Rate Registered Courses\n";
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
				
				OnlineCourse* search2 = findCourse2<SoftwareCourses>(prefix, id, Software, MAX_SOFT);
				if(search2==nullptr)
				search2 = findCourse2<LanguageCourses>(prefix, id, Language, MAX_LANG);
				if (search2 == nullptr)
				search2 = findCourse2<Electives>(prefix, id, Elective, MAX_ELEC);
				if (search2 == nullptr)
				search2 = findCourse2<ProfessionalDevelopmentCourses>(prefix, id, Professional, MAX_PROF);
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
				cout << "Please Select Which Item You Want To Remove From Cart (1-" << ((UserCart.CartStatus()==-1)?3: UserCart.CartStatus()) << ") :"; cin >> toremove; cin.ignore();
				UserCart.RemoveCart(toremove);
			}break;
			case '7': {
				int torate = 0;
				User.ListRegistered();
				if (User.RegisterStatus() == 0)
					break;
				cout << "Please Select Which Item You Want To Rate (1-" << ((User.RegisterStatus() == -1) ? 99 : User.RegisterStatus()) << ") :"; cin >> torate; cin.ignore();
				if (User.getInfo(torate) == true){
					cout << "\nCourse Already Rated!\nWould You like to change your rate? \n[Y] Yes - [N] No "; cin >> choice; fixChoice(&choice), cin.ignore();
					if (choice != 'y'){
						torate = -1;
						break;
					}
				}
				User.rateCourse(torate);
				/*int torate = 0;
				User.ListRegistered();
				if (User.RegisterStatus() == 0)
					break;
				else
					User.ListRegistered();
					cout << "Please Select Which Item You Want To Rate (1-" << ((User.RegisterStatus() == -1) ? 99 : User.RegisterStatus()) << ") :"; cin >> torate; cin.ignore();
					if (torate != -1)
						if (User.getInfo(torate) == true)
						{
							cout << "\nCourse Already Rated!\nWould You like to change your rate? \n[Y] Yes - [N] No "; cin >> choice; fixChoice(&choice), cin.ignore();
							if (choice != 'y')
							{
								torate = -1;
								break;
							}
						}
				if(torate!=-1)
					User.rateCourse(torate);*/

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