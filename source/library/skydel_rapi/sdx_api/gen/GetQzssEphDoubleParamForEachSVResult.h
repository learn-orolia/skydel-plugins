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
    /// Result of GetQzssEphDoubleParamForEachSV
    ///
    /// Name      Type         Description
    /// --------- ------------ --------------------------------------------------------------------------------------------------
    /// ParamName string       Refer to SetQzssEphDoubleParamForSV for accepted names
    /// Val       array double Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class GetQzssEphDoubleParamForEachSVResult;
    typedef std::shared_ptr<GetQzssEphDoubleParamForEachSVResult> GetQzssEphDoubleParamForEachSVResultPtr;
    typedef GetQzssEphDoubleParamForEachSVResult GetQzssEphemerisDoubleParamsResult;
    typedef std::shared_ptr<GetQzssEphemerisDoubleParamsResult> GetQzssEphemerisDoubleParamsResultPtr;
    
    class GetQzssEphDoubleParamForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssEphDoubleParamForEachSVResult();

      GetQzssEphDoubleParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val);
  
      static GetQzssEphDoubleParamForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val);
      static GetQzssEphDoubleParamForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      std::vector<double> val() const;
      void setVal(const std::vector<double>& val);
    };
  }
}

