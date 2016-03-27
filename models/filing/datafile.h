#ifndef DATAFILE_H
#define DATAFILE_H

#include <QDebug>
#include <QHash>
#include <QByteArray>
#include <QMimeData>
#include <QFile>

/**
 * @brief use to manage files deferent fragments. this struct contains the size of the dragment,end,start byts
 */
struct FragmentFrame
{
  /**
   * @brief starting byte of the file fragment
   */
  quint64 start=0;
  /**
   * @brief ending byte og the file fragment
   */
  quint64 end=0;
  /**
   * @brief size of the file fragment
   */
  quint64 size=0;
};

/**
 * @brief The DataFile class provides interface for manage QMimeData object as a file
 * this file is saved as given file name
 */
class DataFile
{
public:
  /**
   * @brief only constructor
   * @param mime data to save as a file
   * @param file name to save
   */
  DataFile(const QMimeData *mimeData,const QString &filename);

  ~DataFile();
  /**
   * @brief get data relavent to given format the returned reference must delete after using it
   * @param format for get data
   * @return new QByteArray object --> its reference (this must be delete after using)
   * return NULL if not availabel
   * return empty ByteArray if data is empty
   */
  QByteArray *data(const QString &format);

  /**
   * @brief use to get format data of given object
   * @param index for get data
   * @return new QByteArray object --> its reference (this must be delete after using)
   * return NULL if not a valid index
   * return empty ByteArray f data is empty
   */
  QByteArray *at(const int &index);

  /**
   * @brief use to check the no data
   * @return true if no data otherwise false
   */
  bool isEmpty();

  /**
   * @brief how much formats in this object
   * @return format count
   */
  int count();
private:
  /**
   * @brief _fragments (Hash for manage formats)
   */
  QHash<QString,FragmentFrame> *_fragments;

  /**
   * @brief file relevent to this object
   */
  QFile *_file;



};

#endif // DATAFILE_H