#pragma once

namespace app::db {
    class DatabaseInterface {
    public:
        virtual bool DI_UnkFunc0() = 0;
        virtual bool DI_UnkFunc1() = 0;
        virtual void* GetData() const = 0;
        virtual hh::fnd::RflClass* GetClass() const = 0;
    };

    class DatabaseEditor {
    public:
        csl::ut::VariableString qword8;
        csl::ut::VariableString resourceName;
        int64_t qword28;
        int64_t qword30;
        DatabaseInterface* dbInterface;

        DatabaseEditor();

        virtual ~DatabaseEditor();

        void Initialize(DatabaseInterface* dbInterface, const char* qword8, const char* resourceName);
    };

    template<typename T, typename U, typename V>
    class Database : public hh::fnd::BaseObject, public DatabaseInterface, public DatabaseEditor {
    public:
        V data;
        csl::ut::MoveArray<T> entries;
        char unk0;

        virtual bool DI_UnkFunc0() override { return false; }
        virtual bool DI_UnkFunc1() override { return false; }

        virtual void* GetData() const override {
            return data;
        };
        
        virtual hh::fnd::RflClass* GetClass() const override {
            return V::GetClass();
        }

        void SetData(U* data, size_t entryCount) {
            if (entryCount > 0) {
                // TODO: Implement
            }
        }

        inline void SetData(U* data) {
            SetData(data, sizeof(U::data)/sizeof(T));
        }
    };

    class DatabaseService : public hh::game::GameService, public fnd::AppResourceManagerListener { 
    public:
        Database<player::EffectRecord, player::EffectRecordBaseTable, player::EffectRecordTable>* effectDatabase;
        Database<level::EnemyAttackRecord, EnemyAttackRecordBaseTable, EnemyAttackRecordTable>* enemyAttackDatabase;
        Database<level::EnemyDefenceRecord, EnemyDefenceRecordBaseTable, EnemyDefenceRecordTable>* enemyDefenceDatabase;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;

        virtual void ARML_UnkFunc1(int unkParam1) override;

        GAMESERVICE_CLASS_DECLARATION(DatabaseService)
    };
}
