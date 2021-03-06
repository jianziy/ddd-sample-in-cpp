#include "domain/model/comm-role/ManInfo.h"
#include "domain/service/AccountService.h"

ManInfo::ManInfo(const std::string& manId, const std::string& name,
		Gender gender, const std::string& phoneNumber, U32 initAmount)
: manId(manId), name(name), gender(gender), phoneNumber(phoneNumber)
{
	accountId = AccountService().createAccount(manId, phoneNumber, initAmount);
}

ManInfo::~ManInfo()
{
	AccountService().destroyAccount(accountId);
}

bool ManInfo::operator==(ValueObject* rhs)
{
	return true;
}

std::string ManInfo::getAccountId() const
{
	return accountId;
}
