#include <iostream>
#include <sstream>

using namespace std;

struct song{		//song struct
	string title;
	string artist;
	int year;	
};

string songToString(song s){		//takes a song and returns the data in the way it should be printed
	stringstream ss; 
	ss << '"' << s.artist << " - " << s.title << " (" << s.year << ")" << '"' << endl;		//uses stringstream to collect all the string
	string str = ss.str();	//assigns string variable the stringstream's contents
	return str;
}

song** songsFromYear(song **songs, int size, int year, int resultSize) {
	song** songsfromYear = new song*[resultSize];	//creates a new song** to hold the songs from the year being searched for
	
	for(int i = 0;i < size; i ++){	//loops through all the indices of the songsfromYear array
		bool found = false;
		int j = 0;
		while(found == false && j < size){	//loops through all the songs until it finds the right one or it loops through all of them
			if(songs[j]->year == year){
					songsfromYear[i] = songs[j];	//makes the **songsFromYear pointer point to the song of the specified year
					found = true;
			}
			j++;
		}
	}
	return songsfromYear;			//returns pointer array that points to the songs of the correct year
}

int main(int argc, char **argv){
	song **array = new song*[5];	//creates dynamically allocated array
	array[0] = new song;			//creates dynamically allocated structs at each index of the array
	array[1] = new song;
	array[2] = new song;
	array[3] = new song;
	array[4] = new song;
	array[0]->title = "Never Gonna Give You Up"; //Assigns values to each index of array
	array[0]->artist = "Rick Astley";
	array[0]->year = 1987;
	array[1]->title = "What Is Love?";
	array[1]->artist = "Haddaway"; 
	array[1]->year = 1993;
	array[2]->title = "Sandstorm";
	array[2]->artist = "Darude";
	array[2]->year = 2000;
	array[3]->title = "Let It Be";
	array[3]->artist = "The Beatles";
	array[3]->year = 1970;
	array[4]->title = "Shake It Off";
	array[4]->artist = "Taylor Swift";
	array[4]->year = 2014;
	
	cout << songToString(*array[0]);	//prints each index of array using songToString() function
	cout << songToString(*array[1]);
	cout << songToString(*array[2]);
	cout << songToString(*array[3]);
	cout << songToString(*array[4]);
	
	int year = 1970;		//year to look for
	int numResults = 1;
	for(int i = 0; i < numResults; i ++){
		cout << "The songs from " << year << " are : " << songToString(*songsFromYear(array, 5, year, numResults)[i]);		//displays song from the year specified
	}
	
	delete array[0];	//deletes all dynamically allocated data
	delete array[1];
	delete array[2];
	delete array[3];
	delete array[4];
	delete array;
}
