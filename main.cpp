#include <QCoreApplication>
#include <QProcess>
#include <QDebug>

QString Wmic(QString command, QString paramName)
{
    QString cpucorp = "wmic " + command + " " + paramName;
    QProcess windowscpu;
    windowscpu.start(cpucorp);
    windowscpu.waitForFinished();
    QString windowsOutput = QString::fromLocal8Bit(windowscpu.readAllStandardOutput());
    windowsOutput.replace(paramName, "");
    return windowsOutput.trimmed();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int CPUloadPercentaje = Wmic("cpu get", "LoadPercentage").toInt();

    qDebug() << CPUloadPercentaje;


    return a.exec();
}
