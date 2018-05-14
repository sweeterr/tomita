#encoding "utf-8"

// через include не получилось - ругается на лишние корни
Country -> AnyWord<kwtype="country">;
Country -> AnyWord<kwtype="country_short_name">;
City -> AnyWord<kwtype="city">;

// субъекты федерации из википедии
RusFedSubj -> AnyWord<kwtype="org_rus_fed">;

OrgDescr -> AnyWord<kwtype="org_descr">;

// межправительственные организации из викидата
OrgIntergov -> AnyWord<kwtype="org_intergov"> | AnyWord<kwtype="org_intergov", quoted>;
// международные организации из викидата
OrgInternat -> AnyWord<kwtype="org_internat"> | AnyWord<kwtype="org_internat", quoted>;
// объединения и союзы из викидата
OrgUnion -> AnyWord<kwtype="org_union"> | AnyWord<kwtype="org_union", quoted>;
// крупнейшие информационные агентства из википедии
OrgNews -> ('информационное') ('агентство') ('агенство') AnyWord<kwtype="org_news"> | AnyWord<kwtype="org_news", quoted>;
// крупнейшие российские фирмы по рейтингу РБК500
OrgRusBus -> AnyWord<kwtype="org_rus_bus"> | AnyWord<kwtype="org_rus_bus", quoted>;
// крупнейшие международные фирмы по рейтингу Fortune500
OrgOtherBus -> AnyWord<kwtype="org_other_bus"> | AnyWord<kwtype="org_other_bus", quoted>;
OrgSite -> ('сайт') ('интернет-ресурс') ('социальный') ('сеть') AnyWord<kwtype="org_site"> | AnyWord<kwtype="org_site", quoted>;
// российские партии
OrgParty -> ('партия') AnyWord<kwtype="org_rus_party", h-reg1> | AnyWord<kwtype="org_rus_party", quoted>;
// газеты, телевизионные каналы и пр. - вручную
OrgMassMedia -> ('русский') ('служба') ('интернет-издание') AnyWord<kwtype="org_mass_media"> | AnyWord<kwtype="org_mass_media", quoted>;

OrgName -> AnyWord<h-reg1, wff=/[A-Za-z\-]+/>+; // латиницей
OrgName -> AnyWord<quoted>; // в кавычках
OrgName -> AnyWord<l-quoted> AnyWord<r-quoted>;
OrgName -> AnyWord<l-quoted> AnyWord AnyWord<r-quoted>; // в кавычках несколько слов

OrgWho -> AnyWord<gram="S,gen">+;

OrgSport -> (GovAdj) 'сборная' Country;
OrgGov -> 'власть'<gram="pl"> Country;
OrgGov -> 'власть'<gram="pl"> RusFedSubj;
OrgGov -> 'власть'<gram="pl"> City;
OrgGov -> 'правительство' Country;
OrgGov -> 'правительство' RusFedSubj;
OrgGov -> 'правительство' City;
OrgGov -> AnyWord<kwtype="org_gov">; // всё, что связано с правительством - вручную
OrgGov -> AnyWord<kwtype="org_gov"> Country;
OrgGov -> AnyWord<kwtype="org_gov"> RusFedSubj;
OrgGov -> AnyWord<kwtype="org_gov"> City;
GovAdj -> 'японский' | 'американский' | 'российский' | 'европейский';
OrgGov -> GovAdj OrgGov;
OrgGov -> OrgGov OrgWho;

OrgDept -> AnyWord<kwtype='org_dept'> OrgGov;
OrgDept -> AnyWord<kwtype='org_dept'> OrgFromList;
OrgDept -> AnyWord<kwtype='org_dept'> OrgName;
OrgDept -> AnyWord<kwtype='org_dept'> Country;
OrgDept -> AnyWord<kwtype='org_dept'> City;
OrgDept -> AnyWord<kwtype='org_dept'> OrgOtherBus;
OrgDept -> AnyWord<kwtype='org_dept'> OrgRusBus;
OrgDept -> AnyWord<kwtype='org_dept'> OrgIntergov;
OrgDept -> AnyWord<kwtype='org_dept'> OrgInternat;
OrgDept -> AnyWord<kwtype='org_dept'> OrgMassMedia;
OrgDept -> AnyWord<kwtype='org_dept'> OrgSport;

OrgFromList -> OrgIntergov;
OrgFromList -> OrgInternat;
OrgFromList -> OrgUnion;
OrgFromList -> OrgNews;
OrgFromList -> OrgRusBus;
OrgFromList -> OrgOtherBus;
OrgFromList -> OrgSite;
OrgFromList -> OrgParty;
OrgFromList -> OrgMassMedia;

Org -> OrgDept interp(Object.Name; Object.Type="ORG");

Org -> 'интернет' interp(Object.Name; Object.Type="ORG");

Org -> OrgFromList interp(Object.Name; Object.Type="ORG");

Org -> OrgGov interp(Object.Name; Object.Type="ORG");
Org -> OrgSport interp(Object.Name; Object.Type="ORG");

Org -> OrgDescr interp(Object.Descr);
Org -> OrgDescr interp(Object.Descr) OrgName interp(Object.Name; Object.Type="ORG");
Org -> OrgDescr interp(Object.Descr) OrgWho interp(Object.Name; Object.Type="ORG");





//OrgState -> AnyWord<kwtype="org_state_type">;
//Org -> OrgState interp(Object.Name; Object.Type="ORG");