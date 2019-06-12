#include <QString>

struct Data {
/* the class stores configuration data in order not to search for them throughout the code
 * Just use: #include "data.cpp"; data Data; Data.host and other
 */

	QString host = "localhost";
	int port = 3306;
	QString user = "twd";
	QString password = "twd_DatabaseUserPassword0";
};
