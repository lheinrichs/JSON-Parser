all: Music.x

Music.x: Album.o AlbumImage.o AlbumImages.o Albums.o Artist.o ArtistImage.o ArtistImages.o Artists.o Track.o Tracks.o JSONArray.o JSONDataItem.o JSONDataObject.o main.o
	g++ -std=c++11 -ggdb -o Music.x Album.o AlbumImage.o AlbumImages.o Albums.o Artist.o ArtistImage.o ArtistImages.o Artists.o Track.o Tracks.o JSONArray.o JSONDataItem.o JSONDataObject.o main.o

Album.o: Album.cpp Album.hpp
	g++ -std=c++11 -ggdb -c -o Album.o Album.cpp

AlbumImage.o: AlbumImage.cpp AlbumImage.hpp
	g++ -std=c++11 -ggdb -c -o AlbumImage.o AlbumImage.cpp

AlbumImages.o: AlbumImages.cpp AlbumImages.hpp
	g++ -std=c++11 -ggdb -c -o AlbumImages.o AlbumImages.cpp

Albums.o: Albums.cpp Albums.hpp
	g++ -std=c++11 -ggdb -c -o Albums.o Albums.cpp

Artist.o: Artist.cpp Artist.hpp
	g++ -std=c++11 -ggdb -c -o Artist.o Artist.cpp

ArtistImage.o: ArtistImage.cpp ArtistImage.hpp
	g++ -std=c++11 -ggdb -c -o ArtistImage.o ArtistImage.cpp

ArtistImages.o: ArtistImages.cpp ArtistImages.hpp
	g++ -std=c++11 -ggdb -c -o ArtistImages.o ArtistImages.cpp

Artists.o: Artists.cpp Artists.hpp
	g++ -std=c++11 -ggdb -c -o Artists.o Artists.cpp

Track.o: Track.cpp Track.hpp
	g++ -std=c++11 -ggdb -c -o Track.o Track.cpp

Tracks.o: Tracks.cpp Tracks.hpp
	g++ -std=c++11 -ggdb -c -o Tracks.o Tracks.cpp

JSONArray.o: JSONArray.cpp JSONArray.hpp
	g++ -std=c++11 -ggdb -c -o JSONArray.o JSONArray.cpp

JSONDataItem.o: JSONDataItem.cpp JSONDataItem.hpp
	g++ -std=c++11 -ggdb -c -o JSONDataItem.o JSONDataItem.cpp

JSONDataObject.o: JSONDataObject.cpp JSONDataObject.hpp
	g++ -std=c++11 -ggdb -c -o JSONDataObject.o JSONDataObject.cpp

main.o: Album.hpp AlbumImage.hpp Albums.hpp Artist.hpp ArtistImage.hpp Artists.hpp Track.hpp Tracks.hpp JSONArray.hpp JSONDataItem.hpp JSONDataObject.hpp main.cpp
	g++ -std=c++11 -ggdb -c -o main.o main.cpp
