#pragma once

enum Actions
{
	action_ping = 0,
	action_ping_response,
	action_auth,
	action_auth_fail,
	action_auth_success,
	action_conf_user,
	action_conf_user_response
};

struct DataFormat
{
	__int64 Account;
	Actions ActionID;
	int PacketID;
	int PacketCountExpected;

	DataFormat(__int64 a, Actions b, int c, int d)
	{
		Account = a;
		ActionID = b;
		PacketID = c;
		PacketCountExpected = d;
	}

	DataFormat()
	{
		Account = -1;
		ActionID = action_ping;
		PacketID = -1;
		PacketCountExpected = -1;
	}
};