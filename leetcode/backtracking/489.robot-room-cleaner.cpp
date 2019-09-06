/*
 * @lc app=leetcode id=489 lang=cpp
 *
 * [489] Robot Room Cleaner
 *
 * https://leetcode.com/problems/robot-room-cleaner/description/
 *
 * algorithms
 * Hard (65.72%)
 * Total Accepted:    28.9K
 * Total Submissions: 44.1K
 * Testcase Example:  '[[1,1,1,1,1,0,1,1],[1,1,1,1,1,0,1,1],[1,0,1,1,1,1,1,1],[0,0,0,1,0,0,0,0],[1,1,1,1,1,1,1,1]]\n1\n3'
 *
 * Given a robot cleaner in a room modeled as a grid.
 * 
 * Each cell in the grid can be empty or blocked.
 * 
 * The robot cleaner with 4 given APIs can move forward, turn left or turn
 * right. Each turn it made is 90 degrees.
 * 
 * When it tries to move into a blocked cell, its bumper sensor detects the
 * obstacle and it stays on the current cell.
 * 
 * Design an algorithm to clean the entire room using only the 4 given APIs
 * shown below.
 * 
 * 
 * interface Robot {
 * // returns true if next cell is open and robot moves into the cell.
 * // returns false if next cell is obstacle and robot stays on the current
 * cell.
 * boolean move();
 * 
 * ⁠ // Robot will stay on the same cell after calling turnLeft/turnRight.
 * // Each turn will be 90 degrees.
 * void turnLeft();
 * void turnRight();
 * 
 * ⁠ // Clean the current cell.
 * ⁠ void clean();
 * }
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * room = [
 * ⁠ [1,1,1,1,1,0,1,1],
 * ⁠ [1,1,1,1,1,0,1,1],
 * ⁠ [1,0,1,1,1,1,1,1],
 * ⁠ [0,0,0,1,0,0,0,0],
 * ⁠ [1,1,1,1,1,1,1,1]
 * ],
 * row = 1,
 * col = 3
 * 
 * Explanation:
 * All grids in the room are marked by either 0 or 1.
 * 0 means the cell is blocked, while 1 means the cell is accessible.
 * The robot initially starts at the position of row=1, col=3.
 * From the top left corner, its position is one row below and three columns
 * right.
 * 
 * 
 * Notes:
 * 
 * 
 * The input is only given to initialize the room and the robot's position
 * internally. You must solve this problem "blindfolded". In other words, you
 * must control the robot using only the mentioned 4 APIs, without knowing the
 * room layout and the initial robot's position.
 * The robot's initial position will always be in an accessible cell.
 * The initial direction of the robot will be facing up.
 * All accessible cells are connected, which means the all cells marked as 1
 * will be accessible by the robot.
 * Assume all four edges of the grid are all surrounded by wall.
 * 
 * 
 */
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
//customerized hash and equal
class myHasher{
public:
    size_t operator()(const pair<int, int>& p) const{
	return p.first*31 + p.second;
    }
};

class myEqual{
public:
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
	return (a.first == b.first) && (a.second == b.second); 
    }
};

class Solution {
    int dirs[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}}; //must be clockwise
    unordered_set<pair<int,int>, myHasher, myEqual> v;
public:
    void goBack(Robot& robot){
	//clockwise
	robot.turnRight();
	robot.turnRight();
	robot.move();
	robot.turnRight();
	robot.turnRight();
    }

    void backtrack(Robot& robot, int r, int c, int d){
	pair<int, int> p(r,c);
	v.insert(p);
	robot.clean();
	
	//most important thing is you need to know your new direction
	//then you know next r and c
	for (int i = 0; i < 4; i++){
	    int nd = (d + i)%4;
	    int nr = r + dirs[nd][0];
	    int nc = c + dirs[nd][1];
	    pair<int, int> pr(nr, nc); 
	    if(v.find(pr) == v.end() && robot.move()){
		backtrack(robot, nr, nc, nd);
		goBack(robot);
	    }
	    // turn to next direction
	    robot.turnRight();
	}
    }

    void cleanRoom(Robot& robot) {
	//implement it in recursive backtrack
	//use the hash set to record the visisted points
	backtrack(robot, 0, 0, 0);		
    }

};
