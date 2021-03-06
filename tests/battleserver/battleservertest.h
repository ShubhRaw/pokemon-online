#ifndef BATTLESERVERTEST_H
#define BATTLESERVERTEST_H

#include <Server/battleanalyzer.h>
#include "../common/test.h"


class BattleInput;
class AdvancedBattleData;

class BattleServerTest : public Test
{
    Q_OBJECT
public:
    BattleServerTest();
    ~BattleServerTest();

    void start(); /* Override to not automatically accept test once run() is over */
    void run();
public slots:
    /* Override this method to test what you want */
    virtual void onBattleServerConnected();
    virtual void onBattleCreated(int b, int p1, int p2, const TeamBattle &team, const BattleConfiguration &conf, const QString &tier);
    virtual void onBattleMessage(int b, int p, const QByteArray&);
protected:
    BattleAnalyzer *analyzer;
protected:
    QHash<int, BattleInput*> battles;
    QHash<int, BattleConfiguration*> confs;
    QHash<int, AdvancedBattleData*> datas;
};

#endif // BATTLESERVERTEST_H
