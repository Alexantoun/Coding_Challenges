def node(self, city = None):
    self.name = city

testCases = int(input())
locations = [""]
for i in range (testCases):
    locations.clear()
    numTrips = int(input())
    locations.append(str(input()))
    for x in range (1,numTrips):
        newPlace = str(input())
        y = 0
        found = False
        for y in range (0, len(locations)):
            if locations[y] == newPlace:
                found = True
                break
        if not found:
            locations.append(newPlace)
    print(len(locations))

