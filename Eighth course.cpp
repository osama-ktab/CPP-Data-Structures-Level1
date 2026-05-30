#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

		/*		FOR Problem Number --[1]--		*/
const string ZeroToNinteen[] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
					"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
					"Seventeen", "Eighteen", "Nineteen" };
const string Tens[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty",
						"Sixty", "Seventy", "Eighty", "Ninety" };

int ReadPositiveNumber(string mes)
{
	int number;
	cout << mes;
	cin >> number;
	return number;
}

string ConvertNumberToWord(long number) 
{
	if (number == 0) return ""; 

	if (number < 20)
		return ZeroToNinteen[number];

	if (number < 100)
		return Tens[number / 10] + (number % 10 != 0 ? " " + ConvertNumberToWord(number % 10) : "");

	if (number < 1000)
		return ConvertNumberToWord(number / 100) + " Hundred" + (number % 100 != 0 ? " " + ConvertNumberToWord(number % 100) : "");

	if (number < 1000000)
		return ConvertNumberToWord(number / 1000) + " Thousand" + (number % 1000 != 0 ? " " + ConvertNumberToWord(number % 1000) : "");

	if (number < 1000000000)
		return ConvertNumberToWord(number / 1000000) + " Million" + (number % 1000000 != 0 ? " " + ConvertNumberToWord(number % 1000000) : "");

	return ConvertNumberToWord(number / 1000000000) + " Billion" + (number % 1000000000 != 0 ? " " + ConvertNumberToWord(number % 1000000000) : "");
}

//________________________________________________________________________________________

		/*		FOR Problem Number --[2]--		*/

bool IsLeapYear(int year)
{
	if (year % 400 == 0)
	{
		return true;
		if(year % 100 == 0)
		{
			if(year %4 == 0)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	else
		return false;
}


//________________________________________________________________________________________


		/*		FOR Problem Number --[3]--		*/

bool IsLeapYearInOneLine(int year)
{
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

//________________________________________________________________________________________

		/*		FOR Problem Number --[4]--		*/

int GetNumberOfdays(int year)
{
	return IsLeapYearInOneLine(year) ? 366 : 365 ;
	
}
int GetNumberOfHours(int year)
{
	return GetNumberOfdays(year) * 24;
}
int GetNumberOfMinutes(int year)
{
	return GetNumberOfHours(year) * 60;
}
int GetNumberOfSeconds(int year)
{
	return GetNumberOfMinutes(year) * 60;
}

void PrintNumberOfDaysHoursMinutesSecondsInYear(int year)
{
	cout << "Number of days    in [" << year << "] " << GetNumberOfdays(year) << endl;
	cout << "Number of hours   in [" << year << "] " << GetNumberOfHours(year) << endl;
	cout << "Number of minutes in [" << year << "] " << GetNumberOfMinutes(year) << endl;
	cout << "Number of seconds in [" << year << "] " << GetNumberOfSeconds(year) << endl;
}

//________________________________________________________________________________________


		/*		FOR Problem Number --[5 & 6]--		*/

short NumberOfDaysInAMonth(short Month, short Year)
{
	return (Month < 1 || Month>12) ? 0 : (Month == 2) ? IsLeapYear(Year) ? 29 : 28 : (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) ? 31 : 30;   

}
short NumberOfHoursInAMonth(short Month, short Year)
{
	return NumberOfDaysInAMonth(Month, Year) * 24;
}
int NumberOfMinutesInAMonth(short Month, short Year)
{
	return NumberOfHoursInAMonth(Month, Year) * 60;
}
int NumberOfSecondsInAMonth(short Month, short Year)
{
	return NumberOfMinutesInAMonth(Month, Year) * 60;
}

void PrintNumberOfDaysHoursMinutesSecondsInMonth(int month, int year)
{
	cout << "Number of days    in [" << year << "/" << month << "] " << NumberOfDaysInAMonth(month, year) << endl;
	cout << "Number of hours   in [" << year << "/" << month << "] " << NumberOfHoursInAMonth(month, year) << endl;
	cout << "Number of minutes in [" << year << "/" << month << "] " << NumberOfMinutesInAMonth(month, year) << endl;
	cout << "Number of seconds in [" << year << "/" << month << "] " << NumberOfSecondsInAMonth(month, year) << endl;
}

//________________________________________________________________________________________

		/*		FOR Problem Number --[7]--		*/

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
		/ 12)) % 7;
}
string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = {
	"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
	return arrDayNames[DayOfWeekOrder];
}

//________________________________________________________________________________________

		/*		FOR Problem Number --[8]--		*/
string GetNameOfMonth(short month)
{
	string arrMonthNames[] = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun",
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return arrMonthNames[month - 1];
}

void PrintMonthCalendar(short  month, short year)
{

	int NumberOfDays;

	int current = DayOfWeekOrder(1, month, year);

	NumberOfDays = NumberOfDaysInAMonth(month, year);


	cout << " \n________________" << GetNameOfMonth(month) << "_________________\n" << endl;
	cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n" << endl;
	int i;
	for(i = 0; i < current; i++)
	{
		cout << "     ";
	}

	for (int day = 1; day <= NumberOfDays; day++)
	{
		printf("%5d", day);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}

	printf("\n____________________________________\n");
}

//________________________________________________________________________________________

		/*		FOR Problem Number --[9]--		*/

void PrintYearCalendar(short year)
{
	printf("\n\t\t\t__________________________________________________\n");
	printf("\n\t\t\t_________________ Calendar - %d ________________\n", year);
	printf("\n\t\t\t__________________________________________________\n");
	for (short month = 1; month <= 12; month++)
	{

		PrintMonthCalendar(month, year);
	}
}

//________________________________________________________________________________________


		/*		FOR Problem Number --[10]--		*/

int NumberOfDaysFromTheBeginingOfTheYear(int day, int month, int year)
{
	int total = 0;
	for (int i = 0; i <= month - 1; i++)
		total += NumberOfDaysInAMonth(i, year);

	total += day;
	return total;
}

//________________________________________________________________________________________

		/*		FOR Problem Number --[11]--		*/

struct sDate
{
	short Year;
	short Month;
	short Day;
};

sDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
{
	sDate Date;
	short RemainingDays = DateOrderInYear;
	short MonthDays = 0;
	Date.Year = Year;
	Date.Month = 1;
	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, Year);
		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}
	return Date;
}

//________________________________________________________________________________________



		/*		FOR Problem Number --[12]--		*/

sDate ReadFullDate()
{
	sDate date;

	date.Day = ReadPositiveNumber("Please enter a day   : ");
	date.Month = ReadPositiveNumber("Please enter a month : ");
	date.Year = ReadPositiveNumber("Please enter a year  : ");

	return date;
}

sDate DateAddDays(int days, sDate Date)
{
	short RemainingDays = days +
		NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month,
			Date.Year);
	short MonthDays = 0;
	Date.Month = 1;
	while (true)
	{
		MonthDays = NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}
	return Date;
}

//________________________________________________________________________________________

		/*		FOR Problem Number --[13]--		*/

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : ((Date1.Year ==
	Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month ==
		Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

//________________________________________________________________________________________


		/*		FOR Problem Number --[14]--		*/

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) ? true : false : false : false;
}

//________________________________________________________________________________________


		/*		FOR Problem Number --[15]--		*/

bool IsLastDayOfMonth(sDate Date)
{
	 return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthOfYear(sDate Date)
{
	return (Date.Month == 12 )? true : false;
}

//________________________________________________________________________________________

		/*		FOR Problem Number --[16]--		*/

sDate IncreseDateByOneDay(sDate Date)
{
	if (IsLastDayOfMonth(Date))
	{
		if (IsLastMonthOfYear(Date))
		{
			Date.Day = 1;
			Date.Month = 1;	
			Date.Year++;
		
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}

	}
	else
	{
		Date.Day++;
	}

	return Date;


}

//________________________________________________________________________________________

		/*		FOR Problem Number --[17]--		*/

int NumberOfDays(sDate Date1, sDate Date2)
{
	int total = 0;
	for (int i = Date1.Month; i <= Date2.Month - 1; i++)
		total += NumberOfDaysInAMonth(i, Date1.Year);

	total += Date1.Day;
	return total;
}

int GetDifferenceInDays(sDate Date1, sDate Date2, bool	IncludeEndDay = false)
{
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreseDateByOneDay(Date1);
	}
	return IncludeEndDay ? ++Days : Days;
}

//________________________________________________________________________________________

		/*		FOR Problem Number --[18]--		*/

sDate GetSystemDate()
{
	sDate Date;
	time_t t = time(0);
	tm now_tm;
	localtime_s(&now_tm, &t);
	Date.Year = now_tm.tm_year + 1900;
	Date.Month = now_tm.tm_mon + 1;
	Date.Day = now_tm.tm_mday;
	return Date;
}

//________________________________________________________________________________________


		/*		FOR Problem Number --[20 >> 32]--		*/

sDate  IncreseDateByTenDay(sDate Date)
{

	for (int i = 0; i < 10; i++)
		Date = IncreseDateByOneDay(Date);

	return Date;
}

sDate  IncreseDateByOneWeekDay(sDate Date)
{

	for (int i = 0; i < 7; i++)
		Date = IncreseDateByOneDay(Date);

	return Date;
}

sDate IncreseDateByXWeekDay(short week, sDate Date)
{
	for (int i = 0; i < week; i++)
		Date = IncreseDateByOneWeekDay(Date);

	return Date;
}

sDate IncreaseDateByOneMonth(sDate Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}
	//last check day in date should not exceed max days in thecurrent month
	// example if date is 31/1/2022 increasing one month shouldnot be 31 / 2 / 2022, it should
	// be 28/2/2022
	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}
	return Date;
}

sDate IncreaseDateByXMonth(sDate Date, int X)
{
	for(int i = 0; i < X; i++)
		Date = IncreaseDateByOneMonth(Date);
	return Date;
}

sDate IncreaseDateByOneYear(sDate Date)
{
	Date.Year++;
	//last check day in date should not exceed max days in thecurrent month
	// example if date is 29/2/2020 increasing one year shouldnot be 29 / 2 / 2021, it should
	// be 28/2/2021
	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}
	return Date;
}

sDate IncreaseDateByXYear(sDate Date, int X)
{
	Date.Year += X;
	return Date;
}

sDate IncreaseDateByOneDecade(sDate Date)
{
	Date.Year += 10;
	return Date;
}

sDate IncreaseDateByOneCentury(sDate Date)
{
	Date.Year += 100;
	return Date;
}


//________________________________________________________________________________________

		/*		FOR Problem Number --[33 >> 46]--		*/

sDate DecreseDateByOneDay(sDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Day = 31;
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
		}

	}
	else
	{
	
		Date.Day--;
	}

	return Date;


}

sDate DecreseDateByTenDay(sDate Date)
{

	for (int i = 0; i < 10; i++)
		Date = DecreseDateByOneDay(Date);

	return Date;
}

sDate  DecreseDateByOneWeekDay(sDate Date)
{

	for (int i = 0; i < 7; i++)
		Date = DecreseDateByOneDay(Date);

	return Date;
}

sDate DecreseDateByXWeekDay(short week, sDate Date)
{
	for (int i = 0; i < week; i++)
		Date = DecreseDateByOneWeekDay(Date);

	return Date;
}

sDate DecreseDateByOneMonth(sDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}
	//last check day in date should not exceed max days in thecurrent month
	// example if date is 31/1/2022 increasing one month shouldnot be 31 / 2 / 2022, it should
	// be 28/2/2022
	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}
	return Date;
}

sDate DecreseDateByXMonth(sDate Date, int X)
{
	for (int i = 0; i < X; i++)
		Date = DecreseDateByOneMonth(Date);
	return Date;
}

sDate DecreseDateByOneYear(sDate Date)
{
	Date.Year--;
	//last check day in date should not exceed max days in thecurrent month
	// example if date is 29/2/2020 increasing one year shouldnot be 29 / 2 / 2021, it should
	// be 28/2/2021
	short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}
	return Date;
}

sDate DecreseDateByXYear(sDate Date, int X)
{
	Date.Year -= X;
	return Date;
}

sDate DecreseDateByOneDecade(sDate Date)
{
	Date.Year -= 10;
	return Date;
}

sDate DecreseDateByOneCentury(sDate Date)
{
	Date.Year -= 100;
	return Date;
}


//________________________________________________________________________________________

		/*		FOR Problem Number --[47 >> 53]--		*/

short DayOfWeekOrder(sDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

bool IsEndOfWeek(sDate Date)
{
	return (DayOfWeekOrder(Date) == 6);
}

bool IsWeekEnd(sDate Date)
{
	short DayIndex = DayOfWeekOrder(Date);
	return (DayIndex == 6 || DayIndex == 5);
}

short DaysUntilEndOfWeek(sDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

short DaysUntilEndOfMonth(sDate Date)
{
	return NumberOfDaysInAMonth(Date.Month, Date.Year) - Date.Day;
}

short DaysUntilEndOfYear(sDate Date)
{
	short Days = 0;
	for (short Month = Date.Month + 1; Month <= 12; Month++)
	{
		Days += NumberOfDaysInAMonth(Month, Date.Year);
	}
	Days += DaysUntilEndOfMonth(Date);
	return Days;
}

//________________________________________________________________________________________

		/*		FOR Problem Number --[56]--		*/

bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2));
}

//________________________________________________________________________________________


		/*		FOR Problem Number --[57]--		*/

short ActualVacationDays(short VacationDays, sDate StartDate, sDate EndDate)
{
	while (IsDate1BeforeDate2(StartDate, EndDate))
	{
		if (!IsWeekEnd(StartDate))
			VacationDays++;
		StartDate = IncreseDateByOneDay(StartDate);
	}
	return VacationDays;
}

//________________________________________________________________________________________

		/*		FOR Problem Number --[58]--		*/

bool IsPeriodAreIntersected(sDate StartPeriod1, sDate EndPeriod1, sDate StartPeriod2, sDate EndPeriod2)
{
	return (IsDate1AfterDate2(EndPeriod1, StartPeriod2) && IsDate1AfterDate2(EndPeriod2, StartPeriod1));

}

//________________________________________________________________________________________


		/*		FOR Problem Number --[59]--		*/
short CalculatPeriodLength(sDate StartPeriod, sDate EndPeriod)
{
	short counter = 0;
	while (IsDate1BeforeDate2(StartPeriod, EndPeriod))
	{
		StartPeriod.Day++;
		counter++;
	}
	return counter;
}

//________________________________________________________________________________________


		/*		FOR Problem Number --[60]--		*/

bool IsDateWithinThePeriod(sDate StartPeriod, sDate EndPeriod, sDate DateCheck)
{
	return (IsDate1BeforeDate2(DateCheck, EndPeriod) && IsDate1AfterDate2(DateCheck, StartPeriod));
}

//________________________________________________________________________________________


		/*		FOR Problem Number --[61]--		*/



//________________________________________________________________________________________



		/*		FOR Problem Number --[62]--		*/

bool ValidateDate(sDate Date)
{
	if (Date.Day < 1 || Date.Day > 31)
		return false;
	if (Date.Month < 0 || Date.Month > 13)
		return false;
	if (Date.Day == 31 || Date.Day == 30 || Date.Day == 28 || Date.Day == 29)
	{
		if (Date.Day != NumberOfDaysInAMonth(Date.Month, Date.Year))
		{
			return false;
		}
	}

	return true;
}

//________________________________________________________________________________________

		/*		FOR Problem Number --[63  +  64]--		*/

vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable
	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length()); /* erase() until
		positon and move to next word. */
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}
	return vString;
}

sDate StringToDate(const  string &StringDate)	
{	
	vector<string> InfoDate = SplitString(StringDate, "/");
	if (InfoDate.size() < 3) {
		throw std::invalid_argument("StringToDate: expected format dd/mm/yyyy");
	}

	sDate Date{};
	try {
		Date.Day = stoi(InfoDate[0]);
		Date.Month = stoi(InfoDate[1]);
		Date.Year = stoi(InfoDate[2]);
	}
	catch (const std::exception& e) {
		throw std::invalid_argument("StringToDate: invalid numeric fields");
	}
	return Date;
}

string DateToString(sDate Date)
{
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

//________________________________________________________________________________________



		/*		FOR Problem Number --[65]--		*/

string ReplaceWordInString(string S1, string StringToReplace,string sRepalceTo)
{
	short pos = S1.find(StringToReplace);
	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(),
			sRepalceTo);
		pos = S1.find(StringToReplace);//find next
	}
	return S1;
}


string FormateDate(sDate Date, string DateFormat = "dd/mm/yyyy")
{
	string FormattedDateString = "";
	FormattedDateString = ReplaceWordInString(DateFormat, "dd",
		to_string(Date.Day));
	FormattedDateString = ReplaceWordInString(FormattedDateString,
		"mm", to_string(Date.Month));
	FormattedDateString = ReplaceWordInString(FormattedDateString,
		"yyyy", to_string(Date.Year));
	return FormattedDateString;
}
string ReadStringDate(string Message)
{
	string DateString;
	cout << Message;
	getline(cin >> ws, DateString);
	return DateString;
}

//________________________________________________________________________________________





							/*			-----MAIN FUNCTION-----			*/		

int main()
{


						/*		FOR Problem Number --[65]--		*/

	string DateString = ReadStringDate("\nPlease Enter Datedd / mm / yyyy ? ");
	sDate Date = StringToDate(DateString);
	cout << "\n" << FormateDate(Date) << "\n";
	cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n";
	cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "Day:dd, Month:mm,Year:yyyy") << "\n";
		system("pause>0");

//________________________________________________________________________________________


						/*		FOR Problem Number --[63  +  64]--		*/
	
	//
	//string DateAsString = "";
	//cout << "Enter date as string dd/mm/yyyy : ";
	//cin >> DateAsString;
	//sDate Date = StringToDate(DateAsString);

	//cout << "\nDay   : " << Date.Day;
	//cout << "\nMonth : " << Date.Month;
	//cout << "\nYear  : " << Date.Year << endl;


	//cout << "\n\n\n Your date as string : " << DateToString << endl;

//________________________________________________________________________________________



						/*		FOR Problem Number --[62]--		*/

	//cout << "Enter date to check : \n\n";
	//cout << "_______Date_______\n\n";
	//sDate Date = ReadFullDate();

	//if (ValidateDate(Date))
	//	cout << "Yes, Date is valide date.";
	//else
	//	cout << "No, Date is not valide date.";
	
//________________________________________________________________________________________


						/*		FOR Problem Number --[61]--		*/



//________________________________________________________________________________________


						/*		FOR Problem Number --[60]--		*/

	//cout << "\t\t________ Period _______\n\n";

	//cout << "\n_______Start Period_______\n\n";
	//sDate StartPeriod = ReadFullDate();

	//cout << "\n________End Period________\n\n";
	//sDate EndPeriod = ReadFullDate();


	//cout << "Enter date to check : \n\n";
	//cout << "_______Date_______\n\n";
	//sDate Date = ReadFullDate();


	//if (IsDateWithinThePeriod(StartPeriod, EndPeriod, Date))
	//	cout << "Yes, Date is within period.";
	//else
	//	cout << "No, Date is not within period.";
	

//________________________________________________________________________________________



						/*		FOR Problem Number --[59]--		*/

	//cout << "\t\t________ Period _______\n\n";
	//cout << "\n_______Start Period_______\n\n";
	//sDate StartPeriod = ReadFullDate();

	//cout << "\n________End Period1________\n\n";

	//sDate EndPeriod = ReadFullDate();

	//cout << "\n\nPeriod length is : " << CalculatPeriodLength(StartPeriod, EndPeriod);

//________________________________________________________________________________________


						/*		FOR Problem Number --[58]--		*/

	//cout << "\t\t________ Period1 _______\n\n";
	//cout << "\n_______Start Period1_______\n\n";
	//sDate StartPeriod1 = ReadFullDate();

	//cout << "\n________End Period1________\n\n";

	//sDate EndPeriod1 = ReadFullDate();


	//cout << "\n\n\t\t________ Period2 _______\n\n";
	//cout << "\n_______Start Period2_______\n\n";
	//sDate StartPeriod2 = ReadFullDate();

	//cout << "\n________End Period2________\n\n";

	//sDate EndPeriod2 = ReadFullDate();

	//if (IsPeriodAreIntersected(StartPeriod1, EndPeriod1, StartPeriod2, EndPeriod2))
	//	cout << "\n\nYes, Periods are OverLap.\n\n";
	//else
	//	cout << "\n\nNo, Periods are not OverLap.\n\n";
	
//________________________________________________________________________________________


						/*		FOR Problem Number --[57]--		*/

	//cout << "_______Date1_______\n\n";

	//sDate Date1 = ReadFullDate();

	//cout << "_______Date1_______\n\n";

	//sDate Date2 = ReadFullDate();

	//cout << endl << "Compar Result is : " << CompareTwoDates(Date1, Date2) << endl;


//________________________________________________________________________________________


						/*		FOR Problem Number --[56]--		*/

	//cout << "_______Date1_______\n\n";

	//sDate Date1 = ReadFullDate();

	//cout << "_______Date1_______\n\n";

	//sDate Date2 = ReadFullDate();

	//if (IsDate1AfterDate2(Date1, Date2))
	//	cout << "\nYes, Date1 is After Date2.";
	//else
	//	cout << "\nNo, Date1 is NOT After Date2.";

//________________________________________________________________________________________


						/*		FOR Problem Number --[55]--		*/

	//cout << "________ Vacation Start _______\n\n";
	//sDate StartDate = ReadFullDate();
	//cout << "\nStart in Day " << DayShortName(DayOfWeekOrder(StartDate)) << " , " << StartDate.Day << "/" << StartDate.Month << "/" << StartDate.Year << endl;

	//short VacationDays = 0;
	//cout << "Please inter vacation days : ";
	//cin >> VacationDays;

	//sDate EndDate = CalculatDaysOfVacation(StartDate, VacationDays);
	//cout << "\nEnd in Day " << DayShortName(DayOfWeekOrder(EndDate)) << " , " << EndDate.Day << "/" << EndDate.Month << "/" << EndDate.Year << endl;

//________________________________________________________________________________________

						/*		Problem Number --[54]--		*/

	//cout << "________ Vacation Start _______\n\n";
	//sDate StartDate = ReadFullDate();
	//cout << "\nStart in Day " << DayShortName(DayOfWeekOrder(StartDate)) << " , " << StartDate.Day << "/" << StartDate.Month << "/" << StartDate.Year << endl;

	//cout << "________ Vacation End _______\n\n";
	//sDate EndDate = ReadFullDate();
	//cout << "\nEnd in Day " << DayShortName(DayOfWeekOrder(EndDate)) << " , " << EndDate.Day << "/" << EndDate.Month << "/" << EndDate.Year << endl;

	//cout << "\nYour vacation is " << ActualVacationDays(0, StartDate, EndDate) << " day(s).\n\n";

//________________________________________________________________________________________

						/*		Problem Number --[47 >> 53]--		*/

	//sDate Date = GetSystemDate();
	//cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date)) << " , " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	//cout << "\nIt is end of week ?" << endl;
	//if (IsEndOfWeek(Date))
	//	cout << "Yes, it is end of week.\n\n";
	//else
	//	cout << "No, it is not end of week.\n\n";


	//cout << "\nIt is weekend ?" << endl;
	//if (IsWeekEnd(Date))
	//	cout << "Yes, it is weekend.\n\n";
	//else
	//	cout << "No, it is not weekend.\n\n";


	//cout << "\nIt is BusinessDay ?" << endl;
	//if (!IsWeekEnd(Date))
	//	cout << "Yes, it is a business day.\n\n";
	//else
	//	cout << "No, it is not a business day.\n\n";

	//cout << "\nDays until end of week" << endl ;
	//cout << DaysUntilEndOfWeek(Date) << " day(s)\n\n";

	//cout << "\nDays until end of month" << endl;
	//cout << DaysUntilEndOfMonth(Date) << " day(s)\n\n";


	//cout << "\nDays until end of year" << endl;
	//cout << DaysUntilEndOfYear(Date) << " day(s)\n\n";


//__________________________________________________________________________________________


						/*		Problem Number --[33 >> 46]--		*/

	//cout << "________Date_______\n\n";

	//sDate Date = ReadFullDate();

	//cout << "\nDate after Decreasing by one day is: ";
	//Date = DecreseDateByOneDay(Date);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after decreasing by ten days is: ";
	//Date = DecreseDateByTenDay(Date);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after decreasing by one week is: ";
	//Date = DecreseDateByOneWeekDay(Date);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after decreasing by 10 weeks is: ";
	//Date = DecreseDateByXWeekDay(10, Date);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after decreasing by one month is: ";
	//Date = DecreseDateByOneMonth(Date);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after Decreasing by 10 months is: ";
	//Date = DecreseDateByXMonth(Date, 10);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after decreasing by one year is: ";
	//Date = DecreseDateByOneYear(Date);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after decreasing by 10 years is: ";
	//Date = DecreseDateByXYear(Date, 10);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after decreasing by one decade is: ";
	//Date = DecreseDateByOneDecade(Date);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after decreasing by one century is: ";
	//Date = DecreseDateByOneCentury(Date);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;


//__________________________________________________________________________________________

						/*		Problem Number --[20 >> 32]--		*/

	//cout << "________Date_______\n\n";

	//sDate Date = ReadFullDate();

	//cout << "\nDate after increasing by one day is: ";
	//Date = IncreseDateByOneDay(Date);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after increasing by ten days is: ";
	//Date = IncreseDateByTenDay(Date);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after increasing by one week is: ";
	//Date = IncreseDateByOneWeekDay(Date);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after increasing by 10 weeks is: ";
	//Date = IncreseDateByXWeekDay(10, Date);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after increasing by one month is: ";
	//Date = IncreaseDateByOneMonth(Date);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after increasing by 10 months is: ";
	//Date = IncreaseDateByXMonth(Date, 10);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after increasing by one year is: ";
	//Date = IncreaseDateByOneYear(Date);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after increasing by 10 years is: ";
	//Date = IncreaseDateByXYear(Date, 10);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after increasing by one decade is: ";
	//Date = IncreaseDateByOneDecade(Date);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	//cout << "\nDate after increasing by one century is: ";
	//Date = IncreaseDateByOneCentury(Date);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;


//__________________________________________________________________________________________


						/*		Problem Number --[18]--		*/

	//cout << "_______Date1_______\n\n";

	//sDate Date1 = ReadFullDate();

	//sDate Date2 = GetSystemDate();

	//cout << "\nYour age is : "
	//	<< GetDifferenceInDays(Date1, Date2) << " Day(s).";

//__________________________________________________________________________________________


						/*		Problem Number --[17]--		*/

	//cout << "_______Date1_______\n\n";

	//sDate Date1 = ReadFullDate();

	//cout << "_______Date1_______\n\n";

	//sDate Date2 = ReadFullDate();


	//cout << "\nDiffrence is: "
	//	<< GetDifferenceInDays(Date1, Date2) << " Day(s).";
	//cout << "\nDiffrence (Including End Day) is: "
	//	<< GetDifferenceInDays(Date1, Date2, true) << " Day(s).";
	//

//__________________________________________________________________________________________


						/*		Problem Number --[16]--		*/
	
	//cout << "________Date_______\n\n";

	//sDate Date = ReadFullDate();

	//cout << "\nDate after increasing by one day is: ";
	//Date = IncreseDateByOneDay(Date);
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

//__________________________________________________________________________________________


						/*		Problem Number --[15]--		*/

	//cout << "________Date_______\n\n";

	//sDate Date = ReadFullDate();

	//if (IsLastDayOfMonth(Date))
	//	cout << "\nYes, Day is the last day of the month.\n";
	//else
	//	cout << "\nNo, Day is NOT the last day of the month.\n";

	//if (IsLastMonthOfYear(Date))
	//	cout << "\nYes, Month is the last month of the year.\n";
	//else
	//	cout << "\nNo, Month is NOT the last month of the year.\n";

//__________________________________________________________________________________________

						/*		Problem Number --[14]--		*/

	//cout << "_______Date1_______\n\n";

	//sDate Date1 = ReadFullDate();

	//cout << "_______Date1_______\n\n";

	//sDate Date2 = ReadFullDate();

	//if (IsDate1EqualDate2(Date1, Date2))
	//	cout << "\nYes, Date1 is Equal to Date2.";
	//else
	//	cout << "\nNo, Date1 is NOT Equal to Date2.";
	
//__________________________________________________________________________________________


						/*		Problem Number --[13]--		*/

	//cout << "_______Date1_______\n\n";

	//sDate Date1 = ReadFullDate();

	//cout << "_______Date1_______\n\n";

	//sDate Date2 = ReadFullDate();

	//if (IsDate1BeforeDate2(Date1, Date2))
	//	cout << "\nYes, Date1 is Less than Date2.";
	//else
	//	cout << "\nNo, Date1 is NOT Less than Date2.";

//__________________________________________________________________________________________


						/*		Problem Number --[12]--		*/

	//sDate Date = ReadFullDate();
	//short days = ReadPositiveNumber("\nHow many days you want to add ? ");

	//Date = DateAddDays(days, Date);

	//cout << "\nDate after adding [" << days << "] days is: ";
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;


//__________________________________________________________________________________________



						/*		Problem Number --[11]--		*/

	//short year = ReadPositiveNumber("Please enter a year    : ");
	//short month = ReadPositiveNumber("Please enter a month   : ");
	//short day = ReadPositiveNumber("Please enter a day     : ");
	//short DaysOrderInYear = NumberOfDaysFromTheBeginingOfTheYear(day, month, year);
	//cout << "\nNumber of Days from the begining of the year is "
	//	<< DaysOrderInYear << "\n\n";
	//sDate Date;
	//Date = GetDateFromDayOrderInYear(DaysOrderInYear, year);
	//cout << "Date for [" << DaysOrderInYear << "] is: ";
	//cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

//__________________________________________________________________________________________


						/*		Problem Number --[10]--		*/

	//short year = ReadPositiveNumber("Please enter a year    : ");
	//short month = ReadPositiveNumber("Please enter a month   : ");
	//short day = ReadPositiveNumber("Please enter a day     : ");

	//cout << "\nNumber Of days From The Begining Of The Year is "
	//	<<	NumberOfdaysFromTheBeginingOfTheYear(day, month, year)<< endl;

//__________________________________________________________________________________________


						/*		Problem Number --[9]--		*/

	//short year = ReadPositiveNumber("Please enter a year    : ");
	//PrintYearCalendar(year);
	
//__________________________________________________________________________________________


						/*		Problem Number --[8]--		*/

	//short year = ReadPositiveNumber("Please enter a year    : ");
	//short month = ReadPositiveNumber("Please enter a month   : ");
	//PrintMonthCalendar(month, year);

//__________________________________________________________________________________________


						/*		Problem Number --[7]--		*/

	//short year = ReadPositiveNumber("Please enter a year    : ");
	//short month = ReadPositiveNumber("Please enter a month   : ");
	//short day = ReadPositiveNumber("Please enter a day     : ");

	//cout << "\nDate :" << day << "/" << month << "/" << year;
	//cout << "\nDay Order : " << DayOfWeekOrder(day, month, year);
	//cout << "\nDay Name : " << DayShortName(DayOfWeekOrder(day,month, year));
	//system("pause>0");
	//return 0;


//__________________________________________________________________________________________


						/*		Problem Number --[6]--		*/

	//short year = ReadPositiveNumber("Please enter a year: ");
	//short month = ReadPositiveNumber("Please enter a month: ");
	//PrintNumberOfDaysHoursMinutesSecondsInMonth(month, year);

//__________________________________________________________________________________________


						/*		Problem Number --[5]--		*/

	//short year = ReadPositiveNumber("Please enter a year: ");
	//short month = ReadPositiveNumber("Please enter a month: ");
	//PrintNumberOfDaysHoursMinutesSecondsInMonth(month, year);

//__________________________________________________________________________________________


						/*		Problem Number --[4]--		*/

	//short year = ReadPositiveNumber("Please enter a year: ");
	//PrintNumberOfDaysHoursMinutesSecondsInYear(year);

//__________________________________________________________________________________________


						/*		Problem Number --[3]--		*/

	//short year = ReadPositiveNumber("Please enter a year: \n");

	//if (IsLeapYearInOneLine(year))
	//	cout << year << " is a leap year." << endl;
	//else
	//	cout << year << " is not a leap year." << endl;

//__________________________________________________________________________________________

			/*		Problem Number --[2]--		*/

	//short year = ReadPositiveNumber("Please enter a year: \n");

	//if (IsLeapYear(year))
	//	cout << year << " is a leap year." << endl;
	//else
	//	cout << year << " is not a leap year." << endl;

//__________________________________________________________________________________________


			/*		Problem Number --[1]--		*/	

	//int number = ReadPositiveNumber("Please enter a positive number: \n");
	//cout << ConvertNumberToWord(number) << endl;

//__________________________________________________________________________________________
	return 0;



}
