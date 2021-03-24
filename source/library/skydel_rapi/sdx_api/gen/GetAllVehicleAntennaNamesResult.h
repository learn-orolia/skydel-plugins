#pragma once

#include <memory>
#include "command_result.h"
#include <vector>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetAllVehicleAntennaNames
    ///
    /// Name         Type         Description
    /// ------------ ------------ -----------------------------
    /// AntennaNames array string A list of antenna model names
    ///

    class GetAllVehicleAntennaNamesResult;
    typedef std::shared_ptr<GetAllVehicleAntennaNamesResult> GetAllVehicleAntennaNamesResultPtr;
    
    
    class GetAllVehicleAntennaNamesResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllVehicleAntennaNamesResult();

      GetAllVehicleAntennaNamesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& antennaNames);
  
      static GetAllVehicleAntennaNamesResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& antennaNames);
      static GetAllVehicleAntennaNamesResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** antennaNames ****
      std::vector<std::string> antennaNames() const;
      void setAntennaNames(const std::vector<std::string>& antennaNames);
    };
  }
}

