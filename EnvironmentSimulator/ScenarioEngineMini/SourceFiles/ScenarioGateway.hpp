#pragma once
//#include "../../RoadManager/roadmanager.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "viRDBIcd.h"


enum GW_POS_TYPE
{
	GW_POS_TYPE_ROAD,
	GW_POS_TYPE_XYH
};

struct ObjectStateStruct
{
	RDB_MSG_HDR_t header;
	RDB_OBJECT_STATE_t obj_state;
	RDB_ROAD_POS_t road_pos;
	GW_POS_TYPE posType;
};

class ObjectState
{
public:
	ObjectState() { setId(-1); }
	ObjectState(int id, std::string name, double timestamp, double x, double y, double z, double h, double p, double r, double speed);
	ObjectState(int id, std::string name, double timestamp, int roadId, int laneId, double laneOffset, double s, double speed);

	int getId() { return state_.obj_state.base.id; }
	std::string getName() { return std::string(state_.obj_state.base.name); }
	double getTimeStamp() { return state_.header.simTime; }

	double getPosX() { return state_.obj_state.base.pos.x; }
	double getPosY() { return state_.obj_state.base.pos.y; }
	double getPosZ() { return state_.obj_state.base.pos.z; }

	double getRotH() { return state_.obj_state.base.pos.h; }
	double getRotP() { return state_.obj_state.base.pos.p; }
	double getRotR() { return state_.obj_state.base.pos.r; }

	double getVelX() { return state_.obj_state.ext.speed.x; }
	double getVelY() { return state_.obj_state.ext.speed.y; }
	double getVelZ() { return state_.obj_state.ext.speed.z; }
	
	int getRoadId() { return state_.road_pos.roadId; }
	int getLaneId() { return state_.road_pos.laneId; }
	double getS() { return state_.road_pos.roadS; }
	double getLaneOffset() { return state_.road_pos.laneOffset; }

	ObjectStateStruct getStruct() { return state_; }

	bool getPosType() { return state_.posType; }
	void Print();

	double convertVelocityToSpeed(double vel_x, double vel_y, double rot_h);

private:
	void setId(int objectId) { state_.obj_state.base.id = objectId; }
	void setName(std::string objectName);
	void setTimeStamp(double timestamp) { state_.header.simTime = timestamp; }

	void setPos(double x, double y, double z, double h, double p, double r, double speed);
	void setRoadPos(int roadId, int laneId, double s, double laneOffset, double speed);

	void setVelocity(double speed);

	ObjectStateStruct state_;
};


class ScenarioGateway
{
public:
	
	ScenarioGateway();
	~ScenarioGateway();

	void reportObject(ObjectState objectState);
	int getNumberOfObjects() { return (int)objectState_.size(); }
	ObjectState getObjectStateByIdx(int idx) { return *objectState_[idx]; }
	ObjectState *getObjectStatePtrByIdx(int idx) { return objectState_[idx]; }
	int getObjectStateById(int idx, ObjectState &objState);

private:
	std::vector<ObjectState*> objectState_;
};

