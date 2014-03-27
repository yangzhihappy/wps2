
#ifndef __HAVE_ARCH_WPS_COMMON_MANNER
#define __HAVE_ARCH_WPS_COMMON_MANNER

#include <QObject>

class WPS_Common_Manner : public QObject
{
	Q_OBJECT
public:
	WPS_Common_Manner(QObject *parent = 0);
	virtual ~WPS_Common_Manner();

	/**
	  *@Description : 
	  *	compare file1 and file2 line by line, 
	  *	if different then output each line with its line number to the diff file
	  *	if ether of the file name is empty, then would return a copy of the other file;
	  *	if both file name is empty, then nothing to be done, an empty string would returned;
	  *@param
	  *	file1 : the name with its absolute path of the first file;
	  *	file2 : the name with its absolute path of the second file;
	  *@return
	  *	success : the file name that include the different of file1 between file2;
	  *	failed : empty string would returned;
	  */
	static void wps_cmp_file(const QString &file1, const QString &file2, const QString & resultFile);
	static QString random_fileName();
private:
	
	static void cmp_file(const QString &file1, const QString &file2, const QString &resultFile);
	
};

#endif

