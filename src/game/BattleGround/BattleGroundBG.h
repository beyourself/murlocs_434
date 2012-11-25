/*
 * Copyright (C) 2005-2012 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef __BattleGroundBG_H
#define __BattleGroundBG_H

#include "Common.h"
#include "BattleGround.h"

enum BG_BG_WorldStates
{
    BG_BG_OP_OCCUPIED_BASES_HORDE       = 1778,
    BG_BG_OP_OCCUPIED_BASES_ALLY        = 1779,
    BG_BG_OP_RESOURCES_ALLY             = 1776,
    BG_BG_OP_RESOURCES_HORDE            = 1777,
    BG_BG_OP_RESOURCES_MAX              = 1780,
    BG_BG_OP_RESOURCES_WARNING          = 1955
/*
    BG_BG_OP_LIGHTHOUSE_ICON            = 1842, //LIGHTHOUSE map icon (NONE)
    BG_BG_OP_LIGHTHOUSE_STATE_ALIENCE   = 1767, //LIGHTHOUSE map state (ALIENCE)
    BG_BG_OP_LIGHTHOUSE_STATE_HORDE     = 1768, //LIGHTHOUSE map state (HORDE)
    BG_BG_OP_LIGHTHOUSE_STATE_CON_ALI   = 1769, //LIGHTHOUSE map state (CON ALIENCE)
    BG_BG_OP_LIGHTHOUSE_STATE_CON_HOR   = 1770, //LIGHTHOUSE map state (CON HORDE)
    BG_BG_OP_WATERWORKS_ICON            = 1845, //WATERWORKS map icon (NONE)
    BG_BG_OP_WATERWORKS_STATE_ALIENCE   = 1772, //WATERWORKS state (ALIENCE)
    BG_BG_OP_WATERWORKS_STATE_HORDE     = 1773, //WATERWORKS state (HORDE)
    BG_BG_OP_WATERWORKS_STATE_CON_ALI   = 1774, //WATERWORKS state (CON ALIENCE)
    BG_BG_OP_WATERWORKS_STATE_CON_HOR   = 1775, //WATERWORKS state (CON HORDE)
    BG_BG_OP_MINE_ICON                  = 1846, //MINE map icon (NONE)
    BG_BG_OP_MINE_STATE_ALIENCE         = 1782, //MINE map state (ALIENCE)
    BG_BG_OP_MINE_STATE_HORDE           = 1783, //MINE map state (HORDE)
    BG_BG_OP_MINE_STATE_CON_ALI         = 1784, //MINE map state (CON ALIENCE)
    BG_BG_OP_MINE_STATE_CON_HOR         = 1785, //MINE map state (CON HORDE)
*/
};

const uint32 BG_BG_OP_NODESTATES[3] = { 1767, 1782, 1772, };

const uint32 BG_BG_OP_NODEICONS[3] = { 1842, 1846, 1845, };

enum BG_BG_ObjectType
{
    // TODO drop them (pool-system should be used for this)
    // buffs
    BG_BG_OBJECT_SPEEDBUFF_LIGHTHOUSE       = 1,
    BG_BG_OBJECT_REGENBUFF_LIGHTHOUSE       = 2,
    BG_BG_OBJECT_BERSERKBUFF_LIGHTHOUSE     = 3,
    BG_BG_OBJECT_SPEEDBUFF_MINE             = 4,
    BG_BG_OBJECT_REGENBUFF_MINE             = 5,
    BG_BG_OBJECT_BERSERKBUFF_MINE           = 6,
    BG_BG_OBJECT_SPEEDBUFF_WATERWORKS       = 7,
    BG_BG_OBJECT_REGENBUFF_WATERWORKS       = 8,
    BG_BG_OBJECT_BERSERKBUFF_WATERWORKS     = 9,
    BG_BG_OBJECT_MAX                        = 10,
};


/* node events */
// node-events are just event1=BG_AB_Nodes, event2=BG_AB_NodeStatus
// so we don't need to define the constants here :)

enum BG_BG_Timers
{
    BG_BG_FLAG_CAPTURING_TIME           = 60000,
};

enum BG_BG_Score
{
    BG_BG_WARNING_NEAR_VICTORY_SCORE    = 1400,
    BG_BG_MAX_TEAM_SCORE                = 1600
};

/* do NOT change the order, else wrong behaviour */
enum BG_BG_Nodes
{
    BG_BG_NODE_LIGHTHOUSE       = 0,
    BG_BG_NODE_WATERWORKS       = 1,
    BG_BG_NODE_MINE             = 2,
    BG_BG_NODES_ERROR           = 255
};

#define BG_BG_NODES_MAX   3

enum BG_BG_NodeStatus
{
    BG_BG_NODE_TYPE_NEUTRAL             = 0,
    BG_BG_NODE_TYPE_CONTESTED           = 1,
    BG_BG_NODE_STATUS_ALLY_CONTESTED    = 1,
    BG_BG_NODE_STATUS_HORDE_CONTESTED   = 2,
    BG_BG_NODE_TYPE_OCCUPIED            = 3,
    BG_BG_NODE_STATUS_ALLY_OCCUPIED     = 3,
    BG_BG_NODE_STATUS_HORDE_OCCUPIED    = 4
};

enum BG_BG_Sounds
{
    BG_BG_SOUND_NODE_CLAIMED            = 8192,
    BG_BG_SOUND_NODE_CAPTURED_ALLIANCE  = 8173,
    BG_BG_SOUND_NODE_CAPTURED_HORDE     = 8213,
    BG_BG_SOUND_NODE_ASSAULTED_ALLIANCE = 8212,
    BG_BG_SOUND_NODE_ASSAULTED_HORDE    = 8174,
    BG_BG_SOUND_NEAR_VICTORY            = 8456
};

enum BG_BG_Objectives
{
    BG_OBJECTIVE_ASSAULT_BASE = 370,
    BG_OBJECTIVE_DEFEND_BASE  = 371
};

#define BG_NORMAL_HONOR_INTERVAL        330
#define BG_WEEKEND_HONOR_INTERVAL       200
#define BG_NORMAL_REPUTATION_INTERVAL   160
#define BG_WEEKEND_REPUTATION_INTERVAL  120
#define BG_BG_ExperiencesTicks          260
#define BG_EVENT_START_BATTLE           9158

// Tick intervals and given points: case 0,1,2,3,4,5 captured nodes
const uint32 BG_BG_TickIntervals[4] = {0, 12000, 6000, 1000};
const uint32 BG_BG_TickPoints[4] = {0, 10, 10, 30};

// WorldSafeLocs ids for 3 nodes, and for ally, and horde starting location
const uint32 BG_BG_GraveyardIds[5] = {1736, 1738, 1735, 1740, 1739};

// x, y, z, o
const float BG_BG_BuffPositions[BG_BG_NODES_MAX][4] = {
    { 1063.39f, 1309.09f, 4.91f, 3.98f },   // Lighthouse
    { 990.95f, 984.46f, 13.01f, 4.57f },    // Waterworks
    { 1196.65f, 1020.01f, 7.97f, 5.74f },   // Mine
};

struct BG_BG_BannerTimer
{
    uint32      timer;
    uint8       type;
    uint8       teamIndex;
};

class BattleGroundBGScore : public BattleGroundScore
{
    public:
        BattleGroundBGScore(): BasesAssaulted(0), BasesDefended(0) {};
        virtual ~BattleGroundBGScore() {};
        uint32 BasesAssaulted;
        uint32 BasesDefended;
};

class BattleGroundBG : public BattleGround
{
    friend class BattleGroundMgr;

    public:
        BattleGroundBG();
        ~BattleGroundBG();

        void Update(uint32 diff) override;
        void AddPlayer(Player *plr) override;
        virtual void StartingEventCloseDoors() override;
        virtual void StartingEventOpenDoors() override;
        void RemovePlayer(Player *plr, ObjectGuid guid) override;
        void HandleAreaTrigger(Player *Source, uint32 Trigger) override;
        virtual bool SetupBattleGround() override;
        virtual void Reset() override;
        void EndBattleGround(Team winner) override;
        virtual WorldSafeLocsEntry const* GetClosestGraveYard(Player* player) override;

        /* Scorekeeping */
        virtual void UpdatePlayerScore(Player *Source, uint32 type, uint32 value) override;

        virtual void FillInitialWorldStates(WorldPacket& data, uint32& count) override;

        /* Nodes occupying */
        virtual void EventPlayerClickedOnFlag(Player *source, GameObject* target_obj) override;

        /* achievement req. */
        bool IsAllNodesControlledByTeam(Team team) const override;
        bool IsTeamScores500Disadvantage(Team team) const { return m_TeamScores500Disadvantage[GetTeamIndex(team)]; }

        uint32 GetPlayerScore(Player *Source, uint32 type);
    private:
        /* Gameobject spawning/despawning */
        void _CreateBanner(uint8 node, uint8 type, uint8 teamIndex, bool delay);
        void _DelBanner(uint8 node, uint8 type, uint8 teamIndex);
        void _SendNodeUpdate(uint8 node);

        /* Creature spawning/despawning */
        // TODO: working, scripted peons spawning
        void _NodeOccupied(uint8 node,Team team);

        int32 _GetNodeNameId(uint8 node);

        void CheckBuggers() override;

        /* Nodes info:
            0: neutral
            1: ally contested
            2: horde contested
            3: ally occupied
            4: horde occupied     */
        uint8               m_Nodes[BG_BG_NODES_MAX];
        uint8               m_prevNodes[BG_BG_NODES_MAX];   // used for performant wordlstate-updating
        BG_BG_BannerTimer   m_BannerTimers[BG_BG_NODES_MAX];
        uint32              m_NodeTimers[BG_BG_NODES_MAX];
        uint32              m_lastTick[PVP_TEAM_COUNT];
        uint32              m_honorScoreTicks[PVP_TEAM_COUNT];
        uint32              m_ReputationScoreTics[PVP_TEAM_COUNT];
        uint32              m_ExperiencesTicks[PVP_TEAM_COUNT];
        bool                m_IsInformedNearVictory;
        uint32              m_honorTicks;
        uint32              m_ReputationTics;
        // need for achievements
        bool                m_TeamScores500Disadvantage[PVP_TEAM_COUNT];
};
#endif
