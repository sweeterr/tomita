#encoding "utf-8"

OrgDescr -> AnyWord<kwtype="org_descr">;

OrgFullName -> AnyWord<kwtype="org_name">;

Org -> OrgDescr interp(Object.Descr) AnyWord<h-reg1> interp(Object.Name; Object.Type="ORG");

Org -> OrgFullName interp(Object.Name; Object.Type="ORG");
