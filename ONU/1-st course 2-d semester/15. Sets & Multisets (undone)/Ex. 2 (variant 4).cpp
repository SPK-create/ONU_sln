#include <iostream>
#include <set>
#include <string>
using namespace std;

class Song {
private:
	string name;
	int duration; // in seconds
public: 
	Song(string n, int d) : name(n), duration(d) {}
	Song(string n) : name(n), duration(0) {}
	Song(int d) : name(""), duration(d) {}
	Song() : name(""), duration(0) {}

	void setDuration(int d) {
		duration = d;
	}
	void setName(string n) {
		name = n;
	}

	string getName() const {
		return name;
	}
	int getDuration() const {
		return duration;
	}
};

//Функтор - функциональный объект, который ведёт себя как функция
struct SongComparator {
	bool operator()(const Song& a, const Song& b) const {
		if (a.getDuration() == b.getDuration()) {
			return a.getName() < b.getName();
		}
		return a.getDuration() < b.getDuration();
	}
};

struct SongPairComparator {
	bool operator()(const pair<string, Song>& a, const pair<string, Song>& b) const {
		if (a.second.getDuration() == b.second.getDuration()) {
			if (a.second.getName() == b.second.getName()) {
				// сортировать по жанру, если всё остальное одинаково
				return a.first < b.first;
			}
			return a.second.getName() < b.second.getName();
		}
		return a.second.getDuration() < b.second.getDuration();
	}
};

// Функция для поиска самой короткой песни
const Song& FindShortestSong(const set<Song, SongComparator>& playlist) {
	if (playlist.empty()) {
		throw runtime_error("Playlist is empty");
	}
	return *(playlist.begin());
}

void PrintAllSongsByGenre(const string& genre, const set<pair<string, Song>, SongPairComparator>& playlist) {
	bool find = false;

	for (auto iter = playlist.begin(); iter != playlist.end(); iter++) {
		if (iter->first == genre) {
			find = true;
		}
	}

	if (find == false) {
		cout << "There is no music of this genre in the playlist" << endl << endl;
		return;
	}

	cout << "Genre " << genre << ":" << endl;
	int k = 1;
	for (auto iter = playlist.begin(); iter != playlist.end(); iter++) {
		if ((*iter).first == genre) {
			cout << k << ". " << iter->second.getName() << " (" << iter->second.getDuration() << " sec)" << endl;
			k++;
		}
	}
	return;
}

void PrintAllGenresPlaylist(const set<pair<string, Song>, SongPairComparator>& playlist) {
	if (playlist.empty()) {
		cout << "Playlist is empty!" << endl;
		return;
	}

	set<string> genres;

	for (auto iter = playlist.begin(); iter != playlist.end(); iter++) {
		genres.insert(iter->first);
	}

	cout << "All available music genres: ";
	for (auto iter = genres.begin(); iter != genres.end(); iter++) {
		cout << *iter << ", ";
	}
	cout << endl;
	return;
}

int main() {
	//Ex. 1
	set<Song, SongComparator> playlist = {
		Song("Imagine", 183),
		Song("Bohemian Rhapsody", 354),
		Song("Yesterday", 125),
		Song("Let It Be", 243)
	};

	cout << "Songs in ascending order of length:" << endl;
	for (const auto& song : playlist) {
		cout << song.getName() << " (" << song.getDuration() << " sec)" << endl;
	}
	cout << endl;

	cout << "The shortest song:" << endl;
	Song shortest_song = FindShortestSong(playlist);
	cout << shortest_song.getName() << " (" << shortest_song.getDuration() << " sec)" << endl << endl;

	//Ex. 2
	set<pair<string, Song>, SongPairComparator> modified_playlist;

	// Rock
	modified_playlist.insert({ "Rock", Song("Bohemian Rhapsody", 354) });
	modified_playlist.insert({ "Rock", Song("Imagine", 183) });
	modified_playlist.insert({ "Rock", Song("Stairway to Heaven", 482) });
	modified_playlist.insert({ "Rock", Song("Hotel California", 390) });

	// Pop
	modified_playlist.insert({ "Pop", Song("Thriller", 358) });
	modified_playlist.insert({ "Pop", Song("Billie Jean", 294) });
	modified_playlist.insert({ "Pop", Song("Like a Prayer", 342) });
	modified_playlist.insert({ "Pop", Song("Uptown Funk", 269) });

	// Jazz
	modified_playlist.insert({ "Jazz", Song("Take Five", 324) });
	modified_playlist.insert({ "Jazz", Song("So What", 545) });
	modified_playlist.insert({ "Jazz", Song("Freddie Freeloader", 585) });
	modified_playlist.insert({ "Jazz", Song("Blue in Green", 329) });

	string genre;
	PrintAllGenresPlaylist(modified_playlist);
	cout << "Type a genre to see all musics of this genre: ";
	cin >> genre;
	cout << endl;
	PrintAllSongsByGenre(genre, modified_playlist);

	cout << "Do you want to add new songs? (y/n): ";
	char answer;
	cin >> answer;

	while (answer == 'y' || answer == 'Y') {
		string newGenre;
		string newSongName;
		int newSongDuration;

		cout << "Enter genre: ";
		cin.ignore(); // Чтобы убрать символ новой строки после предыдущего cin
		getline(cin, newGenre);

		cout << "Enter song name: ";
		getline(cin, newSongName);

		cout << "Enter song duration in seconds: ";
		cin >> newSongDuration;

		modified_playlist.insert({ newGenre, Song(newSongName, newSongDuration) });

		cout << "Song added!" << endl << endl;

		cout << "Do you want to add another song? (y/n): ";
		cin >> answer;
	}

	cout << endl << "Updated list of genres:" << endl;
	PrintAllGenresPlaylist(modified_playlist);
	cout << endl << "Now enter a genre again to view its songs: ";
	cin.ignore(); // очистка буфера после cin
	getline(cin, genre);
	PrintAllSongsByGenre(genre, modified_playlist);

	return 0;
}