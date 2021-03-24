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
    /// Result of GetBeiDouEphDoubleParamForEachSV
    ///
    /// Name      Type         Description
    /// --------- ------------ --------------------------------------------------------------------------------------------------
    /// ParamName string       Refer to SetBeiDouEphDoubleParamForSV for accepted names
    /// Val       array double Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class GetBeiDouEphDoubleParamForEachSVResult;
    typedef std::shared_ptr<GetBeiDouEphDoubleParamForEachSVResult> GetBeiDouEphDoubleParamForEachSVResultPtr;
    typedef GetBeiDouEphDoubleParamForEachSVResult GetBeiDouEphemerisDoubleParamsResult;
    typedef std::shared_ptr<GetBeiDouEphemerisDoubleParamsResult> GetBeiDouEphemerisDoubleParamsResultPtr;
    
    class GetBeiDouEphDoubleParamForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouEphDoubleParamForEachSVResult();

      GetBeiDouEphDoubleParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val);
  
      static GetBeiDouEphDoubleParamForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val);
      static GetBeiDouEphDoubleParamForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
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

