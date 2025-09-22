// COMSC-210 | Lab 13 | Dainiz Almazan
// IDE used: CLion

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	// Initializing vector and outputting address
	vector<string> playlist;
	cout << "Playlist created at address: " << playlist.data() << endl;

	// Reading data from playlist.txt
	cout << "Reading data from file... ";
	string tempSong;
	ifstream infile;
	infile.open("playlist.txt");
	if (infile.good()) {
		for (int i = 0; i < PLAYLIST_SIZE; i++) {
			getline(infile, tempSong);
			playlist[i] = tempSong;
		}
		cout << "Done!" << endl;
	} else
		cout << "Error opening file" << endl;
	infile.close();

	// Outputting whether array is empty to see if items were added correctly
	cout << "Checking if playlist is empty... " << boolalpha << playlist.empty() << endl;

	// Outputting the size of the array
	cout << "The number of songs in the playlist is: " << playlist.size() << endl;

	// Outputting data from playlist array
	cout << "Playlist Contents:" << endl;
	for (const auto &song: playlist)
		cout << song << '\t';

	// Outputting specific songs from the playlist
	cout << endl << "The first song in the playlist is: " << playlist.front() << endl;
	cout << "The last song in the playlist is: " << playlist.back() << endl;
	cout << "The 20th song in the playlist is: " << playlist.at(19) << endl;

	// Sorting playlist in order of ASCII decimal value then outputting modified playlist
	sort(playlist.begin(), playlist.end());
	cout << "Sorted Playlist Contents:" << endl;
	for (const auto &song: playlist)
		cout << song << '\t';

	// Sorting in reverse ASCII decimal value order then outputting modified playlist
	cout << endl << "Reverse Sorted Playlist Contents:" << endl;
	sort(playlist.rbegin(), playlist.rend());
	for (const auto &song: playlist)
		cout << song << '\t';

	// Looking for specific song in playlist using iterator and find()
	string target = "Dreams";
	array<string, PLAYLIST_SIZE>::iterator it;
	it = find(playlist.begin(), playlist.end(), target);
	cout << endl << "The target song \"" << target;
	if (it != playlist.end())
		cout << "\" was found at position: " << it - playlist.begin() << endl;
	else
		cout << " was not found" << endl;

	// Creating a new playlist filled with a specific song using fill()
	array<string, PLAYLIST_SIZE> paprikaPlaylist;
	cout << "New playlist created at address: " << paprikaPlaylist.data() << endl;
	fill(paprikaPlaylist.begin(), paprikaPlaylist.end(), "Paprika");

	// Swapping the original playlist with the new playlist & outputting modified playlist
	cout << "Swapping original playlist contents with new playlist contents..." << endl;
	playlist.swap(paprikaPlaylist);
	cout << "The original playlist now contains:" << endl;
	for (const auto &song: playlist)
		cout << song << '\t';

	return 0;
}