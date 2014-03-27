
#include "wps_common_manner.h"

extern "C" {
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
}

WPS_Common_Manner::WPS_Common_Manner(QObject *parent) : QObject(parent)
{
}

WPS_Common_Manner::~WPS_Common_Manner()
{
}

#include <QtDebug>
void WPS_Common_Manner::wps_cmp_file(const QString &file1, const QString &file2, const QString & resultFile)
{
	qDebug() << "file1 : " << file1;
	qDebug() << "file2 : " << file2;

	cmp_file(file1, file2, resultFile);
}

QString WPS_Common_Manner::random_fileName()
{
	srandom(time(0));
	return "./" + QString::number(random());
}

void WPS_Common_Manner::cmp_file(const QString &_file1, const QString &_file2, const QString &_resultFile)
{
	int rowNum = 0;

	const char * file1 = NULL;
	const char * file2 = NULL;
	const char * resultFile = NULL;

	FILE	*ffile1 = NULL;
	FILE	*ffile2 = NULL;
	FILE	*fresultFile = NULL;
	
	QByteArray byteArray = _file1.toUtf8();
	file1 = byteArray.data();

	byteArray = _file2.toUtf8();
	file2 = byteArray.data();

	byteArray = _resultFile.toUtf8();
	resultFile = byteArray.data();

	size_t buffSize1 = 1024;
	size_t buffSize2 = 1024;
	char *buff1 = (char *)malloc(buffSize1 * sizeof(char));
	if (NULL == buff1) {
		return;
	}
	char *buff2 = (char *)malloc(buffSize2 * sizeof(char)); 
	if (NULL == buff2) {
		goto FREE_BUFF1;
	}

	ffile1 = fopen(file1, "r");	
	
	ffile2 = fopen(file2, "r");
	
	fresultFile = fopen(resultFile, "a");
	if (NULL == fresultFile) {
		goto CLOSE_ALL;
	}

	if (_file1.isEmpty() && _file2.isEmpty()) {
		goto CLOSE_ALL;
	}

	qDebug() << "start copy file ...";
	qDebug() << "file1 is null : " << (ffile1 == NULL);
	qDebug() << "file2 is null : " << (ffile2 == NULL);
	qDebug() << "fresultFile is null : " << (fresultFile == NULL);
	
	if (_file1.isEmpty() || _file2.isEmpty()) {
		FILE *tmpFile = (_file1.isEmpty()) ? ffile2 : ffile1;
		qDebug() << "tmpFile is null : " << (tmpFile == NULL);
		while (getline(&buff1, &buffSize1, tmpFile) >= 0) {
			//fprintf(tmpFile, "%s", buff1);
			//printf("%s\n", buff1);
			fwrite(buff1, 1, strlen(buff1), fresultFile);
		}
		qDebug() << "copy finished ...";
		goto CLOSE_ALL;
	}
	qDebug() << "end copy file !";

	if (NULL == ffile1 || NULL == ffile2 || NULL == fresultFile) {
		goto CLOSE_ALL;
	}
	
	while (getline(&buff1, &buffSize1, ffile1) >= 0 \
		&& getline(&buff2, &buffSize2, ffile2) >= 0) {
		++rowNum;
		if (!(0 == strcmp(buff1, buff2))) {
			fprintf(fresultFile, "<<<<<--row : %d--\n", rowNum);
			fprintf(fresultFile, "local file--------\n");
			fprintf(fresultFile, "%s", buff1);
			fprintf(fresultFile, "remote file-------\n");
			fprintf(fresultFile, "%s", buff2);
			fprintf(fresultFile, ">>>>>\n");

			fflush(fresultFile);
		}

		memset(buff1, '\0', buffSize1);
		memset(buff2, '\0', buffSize2);
	}	
	
CLOSE_ALL:
	if (!(NULL == fresultFile)) {
		fclose(fresultFile);
	}
	
CLOSE_FILE2:
	if (!(NULL == ffile2)) {
		fclose(ffile2);
	}	
CLOSE_FILE1:
	if (!(NULL == ffile1)) {
		fclose(ffile1);
	}	
FREE_BUFF2:
	if (!(NULL == buff2)) {
		free(buff2);
	}
	
FREE_BUFF1:
	if (!(NULL == buff1)) {
		free(buff1);
	}
}




