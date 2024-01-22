/*


# Critical Observation-1: 


-> Example: 

 gas{5, 2, 3, 1, 6}; 
cost{5, 1, 5, 1, 5}; 


1. Here, in our "Naive" approach we were iterating via each index and we were trying to complete a circuit, in a hope that we will find answer. 


2. When we're at 0th station (index), we go till 2nd station (index), and then due to lack of gas we're not able to reach the 3rd station (index), then the ciritcal observation here is that, if I cannot reach 3rd station when I started from 0th station, then there is no possibility that I will be able to reach 3rd station even if I start my circuit from 1st or 2nd station. 


3. And why is this critical observation true? 

--> Basically just before you ran out of gas and you were not able to reach 3rd station, you successfully reached 2nd station, this means that when you started your circuit from 0th station, till the 2nd station, you either reached each station with an empty tank or with a tank which had some fuel, so when you reached 1st station, you reached there with an empty tank and still you were not able to reach 3rd station, and when you reached 2nd station, you had extra gas of worth 1 value in your tank and still you were not able to reach 3rd station, then how is it possible that when you will start circuit from 1st or 2nd station again then this time you will reach 3rd station? 

--> because whenever you start a new circuit, you start it with an empty tank, and if you already reached 1st or 2nd station with an empty tank or with a tank which had some fuel and you were still not able to reach 3rd station, then with respect to these scenarios when you again start a circuit from 1st station, you're again starting with an empty tank so you will obviously again not reach 3rd station and circuit cannot be completed when you start it from 1st station, and same goes for 2nd station, when you had 1 value worth of extra fuel and you were still not able to reach 3rd station, then when you start your circuit from 2nd station you will start from 0 fuel obviously, and when you were not able to reach 3rd station with 1 value worth of extra fuel then how will you be able to reach it now with less fuel this time. 

4. So, basically the critical observation says that our answer, the station from which we start and will be able to complete a circuit doesn't lie between 0th and 3rd station, that's why don't try iterating those index again and don't try starting a new circuit using those stations as the starting point, because it is sure that they're not the answers, start finding your answer from the 3rd station, if we say this statement without reference of my above given example then I just want to say "In our new algorithm, we will start finding our answer again from wherever our car's tank reaches below 0, because your answer lies ahead of you and not behind you in the array in this situation."  


*/




/*


# Critical Observation-2: 


-> Now we know that the answer lies ahead in the array but we don't have to start the circuit from the next index and then iterate over the whole array again to find out whether the next index is the answer or not. 

-> We have processed the array which is behind us, so basically if I can keep track of total gas deficit whenever my currentGas goes below 0, and if I can keep moving ahead while traversing the array and set currentGas to 0 zero again whenever currentGas goes below 0, then at the end I can just check whether from the point when currentGas went below 0 did I have enough surplus gas ahead such that it can fulfill all the scarcity of gas behind in the path, and if yes, then I know my answer. 

-> Just keep track of this answer in a variable and update this variable to the i+1 index whenever at your current ith index the currentGas reaches below 0. 


*/