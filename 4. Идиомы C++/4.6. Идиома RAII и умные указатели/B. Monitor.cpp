#include <map>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class Monitor {
   private:
    using Ptr = ParticipantResults*;
    using ConstPtr = const ParticipantResults*;

    std::map<std::string, std::unique_ptr<ParticipantResults>> byParticipant_;
    std::map<std::string, std::vector<ConstPtr>> byTeam_;
    std::vector<ConstPtr> allResults_;

   public:
    Monitor() = default;
    Monitor(const Monitor&) = delete;
    Monitor& operator=(const Monitor&) = delete;

    Ptr RegisterParticipant(const std::string& login, const std::string& team) {
        if (byParticipant_.count(login))
            throw std::invalid_argument("Participant is already registered");

        auto participant = std::make_unique<ParticipantResults>(login, team);
        Ptr ptr = participant.get();

        byParticipant_[login] = std::move(participant);

        byTeam_[team].push_back(ptr);
        allResults_.push_back(ptr);

        return ptr;
    }

    Ptr GetParticipantResults(const std::string& login) {
        return byParticipant_.at(login).get();
    }

    ConstPtr GetParticipantResults(const std::string& login) const {
        return byParticipant_.at(login).get();
    }

    std::vector<ConstPtr> GetTeamResults(const std::string& team) const {
        return byTeam_.at(team);
    }

    std::vector<ConstPtr> GetAllResults() const {
        return allResults_;
    }
};
