/*
# p = 2 -- prime
# p = 3; (2,4) -- prime
# p = 4; (2,4) (3,6) -- composite
# p = 5; (2,6) (3,6)-- prime
# p = 6; (2,6) (3,6) (5,10) -- composite
# p = 7; (2,8) (3,9) (5,10) -- prime
#      ; (2,8) (3,9) (5,10) (7,14)


1. 

Pseudocode: 
if(isNotPrime()
When I’m looking at 2, look up primeComposite Pair to see if 2 is a value. If not, add it as prime, find it’s next multiple, add that as a pair.
Else
If the number is found in primeCompositePair, 
add key and value and add that as a key value pair
NewComposite = value from the primeComposite Pair just added
currPrime++;
*/

Solution: 

Class Prime {
	Public: 
	int nextComposite = 4;
	Int currNum = 2;
	Int key = 2;
	unordered_map<int,int> primeCompositePair;
	primeCompositePair.insert(make_pair(currPrime,nextComposite));
	currPrime++;

	Prime(){}
	
Bool isComposite(int number) {
Int key = 0;
for( auto Composite: primeCompositePair) {
			if(number == Composite.second) {
				Key = composite.first;
				Return true;
			}
}
Return false;
}
	

	int nextPrime() {
		While(isComposite(currNum)) {
			newComposite = currNum + key;
	primeCompositePair[key] = newComposite;
	currNum++;
}
	if(primeCompositePair.find(currNum) == primeCompositePair.end()) {
		primeCompositePair.insert(make_pair(currNum, 2*currNum));
}
	Else {
		primeCompositePair[currNum] = primeCompositePair[currNum].first + primeComposite[currNum].second;
}
	return currNum; //this is the next prime Number
}

Int main() {
	Prime p;
Int num = p.nextPrime();
	Cout << num << endl;
	Return 0;
}
