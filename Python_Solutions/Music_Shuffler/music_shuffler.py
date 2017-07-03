# think about how to design this system:
# possible design:
# A Track class with Artist and Album members
# A Playlist class with an array of Tracks, and a shuffle function
# Other Stuff:
# Take inputs from a file if possible to build a Track library/Playlist

from random import sample
import sys


class Track(object):
    def __init__(self, name, artist, album, pk):
        self.name = name
        self.artist = artist
        self.album = album
        self.pk = pk


class Playlist(object):
    def __init__(self):
        self.tracks = []

    def add_track(self, new_track):
        if not any(track.pk == new_track.pk for track in self.tracks):
            self.tracks.append(new_track)

    def list(self):
        for track in self.tracks:
            print track.name

    def shuffle(self):
        new_list = sample(self.tracks, len(self.tracks))
        for track in new_list:
            print track.name

# Main program

if len(sys.argv) < 2 or len(sys.argv) > 2:
    print "\aUnexpected number of cmd line args. Expected 1."
    exit(1)

playlist = Playlist()
fin = open(sys.argv[1])
for line in fin:
    track_info = line.split(" ")

    # skip any lines with the wrong number of args
    if not len(track_info) < 4 or len(track_info) > 4:
        playlist.add_track(Track(track_info[0], track_info[1], track_info[2], track_info[3]))

playlist.list()
print "\n"
playlist.shuffle()
fin.close()
