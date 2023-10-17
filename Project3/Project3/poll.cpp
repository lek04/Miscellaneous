#include<iostream>
#include<string>
#include<cctype>
#include <cassert>
using namespace std;

bool isValidStateCode(string stateCode) { //checks for valid statecode

	const string codes =
		"AL.AK.AZ.AR.CA.CO.CT.DE.FL.GA.HI.ID.IL.IN.IA.KS.KY."
		"LA.ME.MA.MD.MI.MN.MS.MO.MT.NE.NV.NH.NJ.NM.NY.NC.ND."
		"OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY."
		"al.ak.az.ar.ca.co.ct.de.fl.ga.hi.id.il.in.ia.ks.ky"
		"la.me.ma.md.mi.mn.ms.mo.mt.ne.nv.nh.nj.nm.ny.nc.nd."
		"oh.ok.or.pa.ri.sc.sd.tn.tx.ut.vt.va.wa.wv.wi.wy."
		"Al.Ak.Az.Ar.Ca.Co.Ct.De.Fl.Ga.Hi.Id.Il.In.Ia.Ks.Ky."
		"La.Me.Ma.Md.Mi.Mn.Ms.Mo.Mt.Ne.Nv.Nh.Nj.Nm.Ny.Nc.Nd."
		"Oh.Ok.Or.Pa.Ri.Sc.Sd.Tn.Tx.Ut.Vt.Va.Wa.Wv.Wi.Wy."
		"aL.aK.aZ.aR.cA.cO.cT.dE.fL.gA.hI.iD.iL.iN.iA.kS.kY."
		"lA.mE.mA.mD.mI.mN.mS.mO.mT.nE.nV.nH.nJ.nM.nY.nC.nD."
		"oH.oK.oR.pA.rI.sC.sD.tN.tX.uT.vT.vA.wA.wV.wI.wY.";
	return (stateCode.size() == 2 &&
		stateCode.find('.') == string::npos &&  // no '.' in stateCode
		codes.find(stateCode) != string::npos);  // match found
}

bool isvalidstatecodewithinsection(string section) { //checks for valid state code
	string statecode = "";
	for (int k = 0; k != 2; k++) { //breaks off state code of stateforecast
		statecode += section.at(k);
	}

	if (isValidStateCode(statecode)) { //inputs only statecode into function
		return true;
	}
	else {
		return false;
	}
}

bool isValidPollString(string pollData) {


	if (pollData == "") { //allows empty string to be valid pollstring 
		return true;
	}

	for (int k = 0; k < pollData.size(); k++) { //loops through all stateforecasts in pollstring

		string newpollData = ""; //takes pollstring and and breaks it into a single stateforecast
		for (; k != pollData.size(); k++) {
			if (pollData.at(k) != ',') {
				newpollData += pollData.at(k);
			}
			else {
				break;
			}
		}
		if (isvalidstatecodewithinsection(newpollData)) { //will check the the state code in the stateforecast
			string numberswithpartyletter = "";
			for (int l = 2; l != newpollData.size(); l++) { //isolates party results from state code
				if (newpollData.at(l) == ' ') { //returns false if detects space within partyresults 
					return false;
					break;
				}
				if (isdigit(newpollData.at(l))) {
					numberswithpartyletter += newpollData.at(l);
				}
				if (isalpha(newpollData.at(l))) {
					numberswithpartyletter += newpollData.at(l);
				}
			}

			if (newpollData.size() > 2) { //allows only digits after state code
				if (!isdigit(newpollData.at(2))) {
					return false;
				}
			}

			int j = 0;
			while (j != numberswithpartyletter.size()) { //runs through all party results within stateforecast
				if (!isalpha(numberswithpartyletter.back())) { //checks if the last char in the partyresult is letter
					return false;
					break;
				}
				if (isdigit(numberswithpartyletter.at(j))) {
					if (numberswithpartyletter.size() < 2) { //prevents code from going out of bounds
						return false;
						break;
					}
					if (isalpha(numberswithpartyletter.at(j + 1))) {
						j += 2;
					}
					else if (isdigit(numberswithpartyletter.at(j + 1))) {
						if (numberswithpartyletter.size() >= 3) { //prevents code from going out of bounds
							if (isalpha(numberswithpartyletter.at(j + 2))) {
								j += 3;
							}
							else {
								return false;
								break;
							}
						}
						else {
							return false;
							break;
						}
					}
				}
				else {
					return false;
					break;
				}
			}
		}
		else {
			return false;
			break;
		}
	}
	return true;
}

int countSeats(string pollData, char party, int& seatCount) {
	if (!isValidPollString(pollData)) {
		return 1;
	}
	if (!isalpha(party)) {
		return 2;
	}
	if (!isValidPollString(pollData) && !isalpha(party)) {
		return 1;
	}
	if (pollData.size() == 2) { //allows just state codes to be valid
		seatCount = 0;
		return 0;
	}
	if (isValidPollString(pollData) && isalpha(party)) { 
		if (islower(party)) { //allows lowercase party letters to be the same as uppercase
			party = toupper(party);
		}
		seatCount = 0;
		for (int p = 0; p != pollData.size(); p++) {
			if (islower(pollData.at(p))) { //makes every letter an uppercase letter
				pollData.at(p) = toupper(pollData.at(p));
			}
			if (pollData.at(p) == party) { //searches for only the letter within party
				//checks if the party result is valid and if it is a 3 character party result
				if (isdigit(pollData.at(p - 2)) && isdigit(pollData.at(p - 1)) && isalpha(pollData.at(p - 3))) {
					seatCount += ((pollData.at(p - 2) - '0') * 10); //adds the digit in the tens place
					seatCount += (pollData.at(p - 1) - '0'); //adds the digit in the ones place
				}
				//checks if the party result is valid and if it is a 2 character party result
				else if (isdigit(pollData.at(p - 1)) && isalpha(pollData.at(p - 2))) {
					seatCount += (pollData.at(p - 1) - '0');
				}
				else {
					break;
				}
			}
		}
		return 0;
	}
	return 0;
}


int main() {
	
}